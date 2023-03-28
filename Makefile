# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 09:48:06 by yodahani          #+#    #+#              #
#    Updated: 2023/03/27 22:13:58 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Werror -Wextra 

RM=rm -rf
NAME=minishell
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
PURPLE=\033[0;35m
COLOR_END=\033[0m
allmsg="$(GREEN)DONE$(COLOR_END)"
msgfclean="$(BLUE)Fclean$(COLOR_END)"
msgclean="$(BLUE)Clean$(COLOR_END)"

TOKEN_DIR=./1.tokenizer/
TOKEN_SRCS= token.c token_helper.c
LXR_DIR=./2.lexer/
LXR_SRCS=ft_lexer.c lexer_helper.c lexer_sanitizer.c

SRCS_DIR=./sources/
SRCS=minishell.c ft_interperter.c ft_intialiser.c expand_helper.c ft_expand.c 

EXEC_DIR=./execution/
EXEC_SRCS=builtins.c env_utils.c builtins_utils2.c



ADDS_DIR=./0.addons/
ADDS_SRCS=ft_strjoin_m.c ft_join_char.c

DEBUG=-Ldebug -ldebug

LIBFT=-Llibft -lft
RL=-lreadline

OBJS= $(SRCS:%.c=$(SRCS_DIR)%.o) $(TOKEN_SRCS:%.c=$(TOKEN_DIR)%.o) $(LXR_SRCS:%.c=$(LXR_DIR)%.o) $(ADDS_SRCS:%.c=$(ADDS_DIR)%.o) $(EXEC_SRCS:%.c=$(EXEC_DIR)%.o)

all: debug msg libft $(NAME)
	@echo $(allmsg)
	clear
	./minishell

msg:
	@echo "$(GREEN)Compiling MINISHELL... $(COLOR_END)"

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(RL) -L ~/homebrew/opt/readline/lib $(DEBUG) $(OBJS) -o $(NAME)
	@printf "\n"
%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@printf "$(GREEN)██"

libft:
	@$(MAKE) -C libft -s

debug:
	@$(MAKE) -C debug -s

clean:
	@echo $(msgclean)
	@$(RM) $(OBJS)
	@$(MAKE) -C debug clean -s
	@$(MAKE) -C libft clean -s

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C debug fclean -s
	@$(MAKE) -C libft fclean -s
	@echo $(msgfclean)

re:fclean all

.PHONY: all clean fclean re libft debug

.SILENT: $(OBJS)
