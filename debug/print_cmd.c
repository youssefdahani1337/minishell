/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:09:15 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 11:32:41 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_cmd(t_cmdtable *cmd)
{
	int	i;

	i = -1;
	write (1, "Command : \\", 10);
	while (cmd->cmd[++i])
		printf("%s\t", cmd->cmd[i]);
	printf("\n");
	while (cmd->out)
	{
		printf("outfile[%d]\t", cmd->out->fd);
		if (cmd->out->error)
			printf("Error : [%s]", cmd->out->error);
		cmd->out = cmd->out->next;
	}
	printf("\n");
	while (cmd->in)
	{
		printf("infile[%d]\t", cmd->in->fd);
		if (cmd->in->error)
			printf("Error : [%s]", cmd->in->error);
		cmd->in = cmd->in->next;
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
