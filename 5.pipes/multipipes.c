/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:19:03 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/16 18:57:32 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

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

int	**ft_pipe(int size)
{
	int	i;
	int	j;
	int	**pipes;

	i = 0;
	j = 0;
	pipes = malloc(size * sizeof(int *));
	if (!pipes)
		return (NULL);
	while (i < size)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			break;
		if (pipe(pipes[i++]) == -1)
			return (NULL);
	}
	if (i < size)
		ft_close(pipes, i);
	return (pipes);
}

int	ft_forking(t_cmdtable *table, char **path, int **pipe, int size)
{
	int	id;

	id = 0;
	while (table)
	{
		table->pid = fork();
		if (table->pid == 0)
		{
			table->pipe = pipe;
			ft_child(table, path, size, id);
		}
		else if (table->pid == -1)
		{
			perror("minishell");
			g_shell.exitsts = 1;
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
		if (waitpid(table->pid, &status, 0) == -1 || !WIFEXITED(status))
		{
			perror("minishell");
			g_shell.exitsts = 1;
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
	path = ft_checkpath(path);
	size = ft_tablesize(table);
	pipe = ft_pipe(size - 1);
	if (!pipe)
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return (0);
	}
	childs = ft_forking(table, path, pipe, size - 1);
	if (!ft_close(pipe, size - 1))
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return (0);
	}
	if (!ft_wait_childs(table, childs))
		return (0);
	return (1);
}
