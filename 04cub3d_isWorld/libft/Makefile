# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:09:55 by pnopjira          #+#    #+#              #
#    Updated: 2023/10/14 18:11:15 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c\
      ft_isdigit.c\
      ft_isalnum.c\
      ft_isascii.c\
      ft_isprint.c\
      ft_strlen.c\
      ft_memset.c\
      ft_bzero.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_strlcpy.c\
      ft_strlcat.c\
      ft_toupper.c\
      ft_tolower.c\
      ft_strchr.c\
      ft_strrchr.c\
      ft_strncmp.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_atoi.c\
      ft_strnstr.c\
      ft_calloc.c\
      ft_strdup.c\
      ft_substr.c\
      ft_strjoin.c\
      ft_strtrim.c\
      ft_split.c\
      ft_itoa.c\
      ft_strmapi.c\
      ft_striteri.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
		
BONUS =	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\

all: $(NAME)

$(NAME):$(SRC)
	@gcc $(FLAGS) -c $(SRC) -I./
	@ar rcs $(NAME) *.o

bonus:
	@gcc $(FLAGS) -c $(SRC) $(BONUS) -I./
	@ar rcs $(NAME) *.o

clean:
	@rm -f *.o
	@echo "LIBFT clean up all object!"

fclean: clean
	@rm -f $(NAME)
	@echo "LIBFT fclean already"

re: fclean all

.PHONY: clean fclean all re  
