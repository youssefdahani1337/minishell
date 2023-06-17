/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:07:09 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/17 11:39:05 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

int	ft_close(int **pipe, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (close(pipe[i][0]) == -1)
			return (0);
		if (close(pipe[i][1]) == -1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_getcmdpath(char *cmd, char **path)
{
	int		i;
	char	*cmdhalf;
	char	*cmdpath;

	i = 0;
	while (path[i])
	{
		cmdhalf = ft_strjoin(path[i], "/");
		cmdpath = ft_strjoin(cmdhalf, cmd);
		free(cmdhalf);
		// if (!cmdpath) (!cmdhalf)
		if (!access(cmdpath, F_OK))
		{
			if (!access(cmdpath, X_OK))
				return (cmdpath);
			free(cmdpath);
			ft_pipes_msg(cmd, "Permission denied", 126);
		}
		free(cmdpath);
		i++;
	}
	return (NULL);
}

int	ft_slash_dot(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == '/')
		return (1);
	while (cmd[i] == '.')
		i++;
	if (cmd[i] == '/')
		return (2);
	return (0);
}

char	*ft_check_cmd(char **cmd, char **path)
{
	int		slash_dot;
	char	*cmdpath;

	if (!cmd || !cmd[0])
		return (NULL);
	slash_dot = ft_slash_dot(cmd[0]);
	if (slash_dot == 1)
		ft_pipes_msg(cmd[0], "No such file or directory", 126);
	cmdpath = ft_getcmdpath(cmd[0], path);
	if (!cmdpath)
	{
		if (slash_dot == 2 || !path)
			ft_pipes_msg(cmd[0], "No such file or directory", 127);
		ft_pipes_msg(cmd[0], "command not found", 127);
	}
	return (cmdpath);
}

void	ft_execute_cmd(char *cmdpath, t_cmdtable *table, int size)
{
	if (dup2(table->in->fd, STDIN_FILENO) == -1 || dup2(table->out->fd, STDOUT_FILENO) == -1 || !ft_close(table->pipe, size))
	{
		perror("minishell");// free what is allocated (struct, globalvar, path, pipe)
		exit(1);
	}
	execve(cmdpath, table->cmd, NULL);
}
