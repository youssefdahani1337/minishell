/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:19:03 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/14 12:02:09 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

int	ft_wait_childs(t_cmdtable *table)
{
	int	status;

	while (table)
	{
		if (waitpid(table->pid, &status, 0) == -1 || !WIFEXITED(status))
		{
			perror("minishell");
			g_shell.exitsts = 1;
			return (0);
		}
		g_shell.exitsts = WEXITSTATUS(status);
		table = table->next;
	}
	return (1);
}

int	ft_pipe(t_cmdtable *table, int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return (0);
	}
	table->pipe = fds;
	return (1);
}

int	ft_forking(t_cmdtable *table, char **path, int *fds)
{
	int	id;
	int	read;

	id = 0;
	read = 0;
	while (table)
	{
		if (!ft_pipe(table, fds))
			return (0);
		table->pid = fork();
		if (table->pid == 0)
			ft_child(table, path, id, read);
		else if (table->pid == -1)
		{
			perror("minishell");
			g_shell.exitsts = 1;
			return (id); // return (id) so I can wait for childs that were created before encountering that problem
		}
		read = fds[0];
		table = table->next;
		id++;
	}
	return (id);
}

int	ft_multipipes(t_cmdtable *table)
{
	char	**path;
	int		*fds;

	path = NULL;
	path = ft_checkpath(path);
	fds = malloc(2 * sizeof(int));
	if (!fds)
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return (0);
	}
	if (!table->next)
		ft_fork_one(table, path);
	ft_forking(table, path, fds); // if failed wait the child that were called befor then exit
	ft_wait_childs(table); // return value check
	return (1);
}
