/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:09:15 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/17 14:18:00 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_cmd(t_cmdtable *cmd)
{
	t_file	*f;
	int		i;

	i = -1;
	write (1, "Command : \\", 10);
	if (!cmd->cmd[0])
		printf("Nocommand [%p]\n", cmd->cmd);
	while (cmd->cmd[++i])
		printf("[%s]\t", cmd->cmd[i]);
	printf("\n");
	f = cmd->out;
	while (f)
	{
	//	if (f->fd != 1)
	//		read_file(f->fd);
	printf ("%d\t", f->fd);
		if (f->error)
			printf("Error : [%s]", f->error);
		f = f->next;
	}
	printf("\n");
	f = cmd->in;
	while (f)
	{
	printf ("%d\t", f->fd);
	//	if (f->fd != 0)
	//		read_file(f->fd);
		if (f->error)
			printf("Error : [%s]", f->error);
		f = f->next;
	}
	printf("\n");
}

void	print_cmd_iter(t_cmdtable *cmd)
{
	while (cmd)
	{
		print_cmd(cmd);
		cmd = cmd->next;
	}
}
