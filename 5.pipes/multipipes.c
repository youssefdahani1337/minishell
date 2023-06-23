/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:19:03 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 03:59:54 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

int	**ft_pipe(int size)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = malloc(size * sizeof(int *));
	if (!pipes)
		return (NULL);
	while (i < size)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
		{
			ft_close(pipes, i - 1);
			ft_freedptr(pipes, i - 1);
			return (NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			ft_close(pipes, i - 1);
			ft_freedptr(pipes, i);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	ft_child(t_cmdtable *table, char **path, int size, int pipe_index)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (table->in && table->in->fd == -1)
		ft_pipes_msg(NULL, table->in->error, 1);
	if (table->out && table->out->fd == -1)
		ft_pipes_msg(NULL, table->out->error, 1);
	if (table->in && table->in->fd == -2)
		table->in->fd = (table->pipe)[pipe_index - 1][0];
	if (table->out && table->out->fd == -2)
		table->out->fd = (table->pipe)[pipe_index][1];
	if (!table->cmd || !table->cmd[0] || ft_isbuiltins(table))
		exit(g_shell.exitsts);
	else
		ft_execute_cmd(ft_check_cmd(table->cmd, path), table, size);
}

int	ft_forking(t_cmdtable *table, char **path, int **pipe, int size)
{
	int	id;

	id = 0;
	while (table)
	{
		table->pid = fork();
		ft_cmd_change(table->cmd);
		if (table->pid == 0)
		{
			table->pipe = pipe;
			ft_child(table, path, size, id);
		}
		else if (table->pid == -1)
		{
			ft_perr_sts();
			return (id);
		}
		table = table->next;
		id++;
	}
	return (id);
}

int	ft_wait_childs(t_cmdtable *table, int childs)
{
	int	i;
	int	status;

	i = 0;
	while (i < childs)
	{
		if (waitpid(table->pid, &status, 0) == -1/* || WIFEXITED(status) != 0*/)
		{
			ft_perr_sts();
			return (0);
		}
		g_shell.exitsts = WEXITSTATUS(status);
		table = table->next;
		i++;
	}
	return (1);
}

int	ft_multipipes(t_cmdtable *table)
{
	char	**path;
	int		**pipe;
	int		size;
	int		childs;

	path = NULL;
	pipe = NULL;
	size = 0;
	childs = 0;
	size = ft_tablesize(table) - 1;
	if (size)
		pipe = ft_pipe(size);
	if (size && !pipe)
		return (ft_perr_sts(), 0);
	path = ft_checkpath(path);
	childs = ft_forking(table, path, pipe, size);
	free_sp(path);
	if (!ft_close(pipe, size))
	{
		ft_freedptr(pipe, size - 1);
		return (ft_perr_sts(), 0);
	}
	if (!ft_wait_childs(table, childs))
		return (ft_freedptr(pipe, size - 1), 0);
	return (ft_freedptr(pipe, size - 1), 1);
}
