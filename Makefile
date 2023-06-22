
CC=cc
include= -I/goinfre/hbenabad/homebrew/opt/readline/include
CFLAGS= -Wall -Werror -Wextra 
#-fsanitize=address -g3

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
TOKEN_SRCS= token.c
LXR_DIR=./2.lexer/
LXR_SRCS=lexer_syntax.c ft_lexer.c lexer_helper.c lexer_sanitizer.c
PAR_DIR=./3.parser/
PAR_SRCS=parser_addons.c parser_helper.c ft_parser.c heredoc.c expand_helper.c ft_expand.c parse_str_sapce.c parse_redirction.c


SRCS_DIR=./sources/
SRCS=minishell.c ft_interperter.c ft_intialiser.c files_adds.c fill_s_adds.c fill_struct.c execution.c free_me.c

BUILT_DIR=./4.built-ins/
BUILT_SRCS=echo.c cd.c env.c pwd.c unset.c exit.c env_utils.c is_builtin.c export_helper.c export.c export_rank.c

MPIPE_DIR=./5.pipes/
MPIPE_SRCS=multipipes.c path.c multi_childs.c

ADDS_DIR=./0.addons/
ADDS_SRCS=signals.c atoi_m.c check_space.c ft_strjoin_m.c ft_join_char.c print_error.c split_adds.c execution_utils.c change_cmd.c

DEBUG=-Ldebug -ldebug

LIBFT=-Llibft -lft
RL=-L /goinfre/$(USER)/homebrew/opt/readline/lib  -lreadline

OBJS= $(ADDS_SRCS:%.c=$(ADDS_DIR)%.o) $(SRCS:%.c=$(SRCS_DIR)%.o) $(TOKEN_SRCS:%.c=$(TOKEN_DIR)%.o)  $(LXR_SRCS:%.c=$(LXR_DIR)%.o)  $(PAR_SRCS:%.c=$(PAR_DIR)%.o) $(BUILT_SRCS:%.c=$(BUILT_DIR)%.o) $(MPIPE_SRCS:%.c=$(MPIPE_DIR)%.o)
all: debug msg libft $(NAME)
	@echo $(allmsg)

msg:
	@echo "$(GREEN)Compiling MINISHELL... $(COLOR_END)"

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(include) $(LIBFT) $(RL) $(DEBUG) $(OBJS) -o $(NAME)
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
