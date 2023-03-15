# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 09:48:06 by yodahani          #+#    #+#              #
#    Updated: 2023/03/15 12:36:56 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3
RM=rm -rf
NAME=minishell
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
PURPLE=\033[0;35m
COLOR_END=\033[0m
allmsg="$(GREEN)DONE$(COLOR_END)"
fcleanmsg="$(BLUE)Fclean$(COLOR_END)"
cleanmsg="$(BLUE)Clean$(COLOR_END)"

SRCS_DIR=./sources/
EXEC_DIR=./execution/
PARS_DIR=./parsing/
SRCS=minishell.c
DEBUG=-Ldebug -ldebug
LIBFT=-Llibft -lft
RL=-lreadline

OBJS=$(SRCS:%.c=$(SRCS_DIR)%.o)

all: debug msg libft   $(NAME)
	@echo $(allmsg)
	./minishell
msg:
	@echo "$(GREEN)Compiling MINISHELL... $(COLOR_END)"

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(RL) $(DEBUG) $(OBJS) -o $(NAME)
	@printf "\n"
%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@printf "$(GREEN)██"
libft:
	@$(MAKE) -C libft -s

debug:
	@$(MAKE) -C debug -s

clean:
	@echo "$(RED)Delting files $(COLOR_END)"
	@$(RM) $(OBJS)
	@$(MAKE) -C debug clean -s
	@$(MAKE) -C libft clean -s

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C debug fclean -s
	@$(MAKE) -C libft fclean -s
	@echo $(fcleanmsg)

re:fclean all

.PHONY: all clean fclean re libft debug

.SILENT: $(OBJS)
