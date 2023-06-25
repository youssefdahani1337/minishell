/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:23:06 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/25 01:35:35 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

int	ft_isbuiltins(t_cmdtable *table)
{
	if (!ft_strcmp(table->cmd[0], "exit"))
		ft_exit(table);
	else
	{
		g_shell.exitsts = 0;
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
		else if (!ft_strcmp(table->cmd[0], "export"))
			ft_export(table);
		else
			return (0);
	}
	return (1);
}
