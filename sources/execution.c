/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/10 10:51:25 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isbuiltins(t_cmdtable *table)
{
	if (!table->cmd[0])
		return (0);
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
	return (1);
}

void	ft_execution(t_cmdtable *table)
{
	if (table->next== NULL)
	{
		ft_isbuiltins(table);
		//	ft_multipipes(table);
	}
}
