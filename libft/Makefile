# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:02:51 by yodahani          #+#    #+#              #
#    Updated: 2023/06/24 12:46:23 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
COLOR_END=\033[0m

CC = cc
CFLAGS =  -Wall -Wextra -Werror

SRC =	ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_substr.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_strcmp.c

OBJ= $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
clean:
	rm -f ${OBJ}
	rm -f ${OBJ_bonus}
fclean: clean
	rm -f $(NAME)

re: fclean all
