/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/23 19:17:40 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execution(t_cmdtable *table)
{
	if (table)
	{
		if (table->cmd && table->cmd[0] && !table->next && ft_isbuiltins(table))
		{
			if (table->in && table->in->fd == -1)
				ft_print_msg(NULL, table->in->error, 1);
			if (table->out && table->out->fd == -1)
				ft_print_msg(NULL, table->in->error, 1);
			// ft_cmd_change(table->cmd);
		}
		else
			ft_multipipes(table);
	}
	return ;
}
