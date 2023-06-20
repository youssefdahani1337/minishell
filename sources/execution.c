/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/20 18:30:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execution(t_cmdtable *table)
{
	// if (!g_shell.env)
	// 	return ; // check it in another place
	if (table)
	{
		if (table->cmd && table->cmd[0] && !table->next && ft_isbuiltins(table))
			return ;
		else
			ft_multipipes(table);
	}
}
