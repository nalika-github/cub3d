# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 19:22:54 by ptungbun          #+#    #+#              #
#    Updated: 2023/07/11 19:22:56 by ptungbun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	cub3d
HDF				=	cub3d.h game_setup.h get_next_line.h
LIBFT			=	libft/libft.a
CC				=	gcc
CFLAGS			=
# CFLAGS			=	-Wall -Werror -Wextra
# CFLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address

# Variable declaration of directory
INCS_DIR		= ../includes
BUILD_DIR		= ./build

# Variable declaration of file

SRCS			=	main.c init_main_struc.c init_ray_data.c
# SRCS			=	main.c init_main_struc.c init_ray_data.c
HDFS			=	$(HDF:%.h=$(INCS_DIR)/%.h)
OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# Variable declaration of linking lib

OPENDIR			=	-I./libft -I$(INCS_DIR) -L./libft -Lmlx_linux -L/usr/lib
LIBLINK			=	-lft -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OPENDIR) $(OBJS) -o $(NAME) $(LIBLINK)

$(OBJS): $(BUILD_DIR)/%.o: %.c $(HDFS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPENDIR) -c $< -o $@ $(LIBLINK)

$(LIBFT):
	make -C libft

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
