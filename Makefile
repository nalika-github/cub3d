# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:19:47 by pnopjira          #+#    #+#              #
#    Updated: 2023/11/26 23:44:24 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -fsanitize=address -g
#CFLAGS	:= -Wall -Wextra -Werror -g
M		:= make

SRC		:= cub3d.c
UTILS_1_SRC	:=	$(wildcard pnopjira_utils/*.c)
UTILS_2_SRC	:=	$(wildcard ptungbun_utils/*.c)

OBJS	:=	$(SRC:.c=.o)\
			$(UTILS_1_SRC:.c=.o)\
			$(UTILS_2_SRC:.c=.o)
LIBFT	:= ./libft/libft.a
MLX		:= ./mlx/libmlx.a
INC		:= cub3d.h

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

all: sub-make $(NAME)

sub-make:
	$(M) bonus -C libft
	$(M) -C mlx

$(NAME): $(OBJS) $(LIBFT) $(SRC) sub-make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

clean:
	@$(M) clean -C libft
	@$(M) clean -C mlx
	@rm -rf *.o pnopjira_utils/*.o ptungbun_utils/*.o
	@echo "CUB3D clean up all object!"
fclean:
	@$(M) fclean -C libft
	@$(M) fclean -C mlx
	@rm -rf *.o pnopjira_utils/*.o ptungbun_utils/*.o
	@echo "CUB3D clean up all object!"
	@rm -rf $(NAME)
	@echo "CUB3D fclean already"

re: fclean all
