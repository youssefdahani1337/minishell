/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:45:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/21 22:10:16 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execution(t_cmdtable *table)
{
	if (table)
	{
		if (table->cmd && table->cmd[0] && !table->next && ft_isbuiltins(table))
			return ;
		else
			ft_multipipes(table);
	}
}
