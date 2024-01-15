# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:19:47 by pnopjira          #+#    #+#              #
#    Updated: 2024/01/14 10:05:49 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= cub3d
CC      	= gcc
CFLAGS  	= -Wall -Wextra -Werror -fsanitize=address -g
#	CFLAGS := -Wall -Wextra -Werror -g

BUILD_DIR   = build/
INCS_DIR    = includes
SRC         = cub3d.c
UTILS_1_SRC = $(wildcard pnopjira_utils/*.c)
UTILS_2_SRC = $(wildcard ptungbun_utils/*.c)
OBJS        = $(addprefix $(BUILD_DIR), $(SRC:.c=.o) $(UTILS_1_SRC:.c=.o) $(UTILS_2_SRC:.c=.o))
LIBFT       = ./libft/libft.a
MLX         = ./mlx/libmlx.a
INC         = cub3d.h

M       	= make

#	for linux
# OPENDIR			=	-I./libft -I$(INCS_DIR) -L./libft -Lmlx_linux -L/usr/lib
# LIBLINK			=	-lft -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz
#	for mac
OPENDIR		= -I./libft -I$(INCS_DIR) -L./libft -Lmlx -L/usr/lib
LIBLINK		= -lft -lmlx -Imlx  -framework OpenGL -framework AppKit

DEPS        = $(OBJS:.o=.d)

all: sub-make $(NAME)

sub-make:
	$(M) bonus -C libft
	$(M) -C mlx

$(NAME): $(OBJS) $(LIBFT) $(SRC) sub-make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OPENDIR) $(LIBLINK)

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)pnopjira_utils/%.o: pnopjira_utils/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)ptungbun_utils/%.o: ptungbun_utils/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

build: $(OBJS)

-include $(DEPS)

clean:
	@$(M) clean -C libft
	@$(M) clean -C mlx
	@rm -rf $(BUILD_DIR)
	@echo "CUB3D clean up all object!"

fclean:
	@$(M) fclean -C libft
	@$(M) fclean -C mlx
	@rm -rf $(BUILD_DIR)
	@rm -rf $(NAME)
	@echo "CUB3D clean up all object and executable!"

re: fclean all

.PHONY: all clean fclean re