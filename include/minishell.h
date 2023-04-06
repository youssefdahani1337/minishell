/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:26 by yodahani          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/01 13:09:45 by hbenabad         ###   ########.fr       */
=======
/*   Updated: 2023/04/04 15:26:50 by yodahani         ###   ########.fr       */
>>>>>>> 0681aa5b2ff7ef3d68140a0de68f327762cc2923
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL_PROMPT "\033[0;32m [minishell] %>\033[0m"
# define MINISHELL_PROMPT_ERROR "\033[0;31m [minishell] %>\033[0m"

# include "structs.h"
# include "parser.h"
# include "../debug/debug.h"
#include "../execution/execution.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int		ft_minishell(char *line);
void	ft_intialize_shell(char **env);

t_shell	g_shell;

#endif