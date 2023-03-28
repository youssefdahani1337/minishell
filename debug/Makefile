# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 09:58:51 by yodahani          #+#    #+#              #
#    Updated: 2023/03/26 12:28:45 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Werror -Wextra 
#-fsanitize=address -g3
RM=rm -rf
NAME=libdebug.a
SRC= $(wildcard *.c)

OBJ= $(SRC:%.c=%.o)

all: $(NAME)
	@echo "\033[0;35mDebugging Mode \033[0m"
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}
fclean: clean
	rm -f $(NAME)

re: fclean all