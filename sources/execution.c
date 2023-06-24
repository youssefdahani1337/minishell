/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/24 16:03:07 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execution(t_cmdtable *table)
{
	if (table)
	{
		if (table->cmd && table->cmd[0] && !table->next)
		{
			if (table->in && table->in->fd == -1)
			{
				ft_print_msg(table->in->error, 1);
				return ;
			}
			if (table->out && table->out->fd == -1)
			{
				ft_print_msg(table->out->error, 1);
				return ;
			}
			if (ft_isbuiltins(table))
				return ;
			// ft_cmd_change(table->cmd);
		}
		ft_multipipes(table);
	}
	return ;
}
