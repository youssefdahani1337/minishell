/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:35:41 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 14:14:58 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

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

void	ft_freedptr(int **pipes, int size)
{
	if (!pipes)
		return ;
	while (size >= 0)
		free(pipes[size--]);
	free(pipes);
	return ;
}
