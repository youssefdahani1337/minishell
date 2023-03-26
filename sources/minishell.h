/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:26 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 11:21:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL_PROMPT "\033[0;32m [minishell] %>\033[0m"
# include "structs.h"
#include "../2.lexer/lexer.h"
# include "../debug/debug.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_minishell(char *line);
void	ft_intialize_shell(t_shell **shell, char **env);
#endif