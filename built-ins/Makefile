# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 18:21:17 by hbenabad          #+#    #+#              #
#    Updated: 2023/05/30 09:53:47 by hbenabad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g
SRCS= echo.c cd.c env.c env_utils.c main.c
OBJS= ${SRCS:.c=.o}
NAME= exec

all:$(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -L ../libft -lft -o $(NAME)
libft:
	$(MAKE) -C ../libft
clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re: fclean all

.PHONY: libft
