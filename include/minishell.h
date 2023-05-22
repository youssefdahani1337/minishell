
#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL_PROMPT "\033[0;32m [minishell] %>\033[0m"
# define MINISHELL_PROMPT_ERROR "\033[0;31m [minishell] %>\033[0m"

# include "parser.h"
#include "../debug/debug.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int		ft_minishell(char *line);
void	ft_intialize_shell(char **env);


#endif