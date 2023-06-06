/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/06 16:05:12 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execution(t_cmdtable *table)
{
	if (!ft_strcmp(table->cmd[0], "echo"))
		ft_echo(table);
	else if (!ft_strcmp(table->cmd[0], "pwd"))
		ft_pwd(table);
	else if (!ft_strcmp(table->cmd[0], "cd"))
		ft_cd(table);
	else if (!ft_strcmp(table->cmd[0], "env"))
		ft_env(table);
}
