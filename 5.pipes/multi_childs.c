/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:07:09 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/12 20:15:27 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

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
		// if (!cmdpath)
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

char	*ft_check_cmd(char **cmd, char **path)
{
	int		slash_dot;
	char	*cmdpath;

	// if (opendir(cmd[0]))
	// 	ft_pipes_msg(cmd[0], "is a directory", 126);
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

void	ft_execute_cmd(char *cmdpath, t_cmdtable *table, int read)
{
	if (table->in->fd == -3)
		ft_pipes_msg("infile", "Is a directory", 1);
	if (table->in->fd == -2)
	{
		printf("%d\n", read);
		table->in->fd = read;
	}
	if (table->out->fd == -2)
		table->out->fd = table->pipe[1];
	if (dup2(table->in->fd, 0) == -1 || dup2(table->out->fd, 1) == -1)
	{
		perror("minishell");// free what is allocated (struct, globalvar, path)
		exit(1);
	}
	execve(cmdpath, table->cmd, NULL);
}

void	ft_child(t_cmdtable *table, char **path, int id, int read)
{
	if (!id)
		close(table->pipe[0]);
	else
		close(table->pipe[1]);
	if (table->in->fd == -1) //in infile directory check will be done after checking cmd
		ft_pipes_msg("infile", table->in->error, 1);
	if (table->out->fd == -1 || table->out->fd == -3)
		ft_pipes_msg("outfile", table->out->error, 1);
	if (!table->cmd || ft_isbuiltins(table))
	{
		// free what is allocated (struct, globalvar, path)
		exit(0);
	}
	else
		ft_execute_cmd(ft_check_cmd(table->cmd, path), table, read);
}
