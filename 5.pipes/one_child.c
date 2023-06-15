/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:10:45 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/14 15:18:33 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

void	ft_exec_onecmd(char *cmdpath, t_cmdtable *table)
{
	if (table->in->fd == -3)
		ft_pipes_msg("infile", "Is a directory", 1);
	if (dup2(table->in->fd, 0) == -1 || dup2(table->out->fd, 1) == -1)
	{
		perror("minishell");// free what is allocated (struct, globalvar, path)
		exit(1);
	}
	execve(cmdpath, table->cmd, NULL);
}

void	ft_one_child(t_cmdtable *table, char **path)
{
	if (table->in->fd == -1) //in infile directory check will be done after checking cmd
		ft_pipes_msg("infile", table->in->error, 1);
	if (table->out->fd == -1)
		ft_pipes_msg("outfile", table->out->error, 1);
	if (!table->cmd || ft_isbuiltins(table))
	{
		// free what is allocated (struct, globalvar, path)
		exit(0);
	}
	else
		ft_exec_onecmd(ft_check_cmd(table->cmd, path), table);
}

int	ft_fork_one(t_cmdtable *table, char **path)
{
	table->pid = fork();
	if (table->pid == 0)
		ft_one_child(table, path);
	else if (table->pid == -1)
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return (0); // return (id) so I can wait for childs that were created before encountering that problem
	}
	return (1);
}
