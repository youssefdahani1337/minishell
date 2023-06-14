/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/14 11:59:56 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isbuiltins(t_cmdtable *table)
{
	if (!ft_strcmp(table->cmd[0], "echo"))
		ft_echo(table);
	else if (!ft_strcmp(table->cmd[0], "pwd"))
		ft_pwd(table);
	else if (!ft_strcmp(table->cmd[0], "cd"))
		ft_cd(table);
	else if (!ft_strcmp(table->cmd[0], "env"))
		ft_env(table);
	else if (!ft_strcmp(table->cmd[0], "unset"))
		ft_unset(table);
	else if (!ft_strcmp(table->cmd[0], "exit"))
		ft_exit(table);
	else
		return (0);
	// free cmd
	return (1);
}

void	ft_execution(t_cmdtable *table)
{
	if (!g_shell.env)
		return ; // check it in another place
	if (table)
	{
		if (table->cmd && ft_isbuiltins(table) && !table->next)
			return ;
		else
			ft_multipipes(table);
	}
}
