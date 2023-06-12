/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:09:15 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/10 18:07:22 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_cmd(t_cmdtable *cmd)
{
	int		i;
	t_file *out;
	t_file *in;

	i = -1;
	out = cmd->out;
	write (1, "Command : \\", 10);
	while (cmd->cmd[++i])
		printf("[%s]\t", cmd->cmd[i]);
	printf("\n");
	while (out)
	{
		printf("outfile[%d]\t", out->fd);
		if (out->error)
			printf("Error : [%s]", out->error);
		out = out->next;
	}
	printf("\n");
	in = cmd->in;
	while (in)
	{
		printf("infile[%d]\t", in->fd);
		if (in->error)
			printf("Error : [%s]", in->error);
		in = in->next;
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
