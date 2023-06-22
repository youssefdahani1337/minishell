/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:35:41 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/22 11:03:32 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

void	ft_errmsg_sts(char *cmd, char *str, char *err)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(err, 2);
	g_shell.exitsts = 1;
}

void	ft_perr_sts(void)
{
	perror("minishell");
	g_shell.exitsts = 1;
	return ;
}

void	ft_pipes_msg(char *name, char *str, int exitsts)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(exitsts);
}

int	ft_tablesize(t_cmdtable *table)
{
	int	i;

	i = 0;
	while (table)
	{
		i++;
		table = table->next;
	}
	return (i);
}

void	ft_freedptr(int **pipes, int size)
{
	while (size >= 0)
		free(pipes[size--]);
	free(pipes);
	return ;
}
