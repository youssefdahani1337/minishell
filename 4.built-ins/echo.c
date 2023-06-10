/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:10 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/06 16:40:30 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_echo(t_cmdtable *table)
{
	int	i;
	int	j;

	i = 0;
	while ((table->cmd + 1)[i])
	{
		j = 0;
		if ((table->cmd + 1)[i][j] == '-' && ++j)
			while ((table->cmd + 1)[i][j] && (table->cmd + 1)[i][j] == 'n'
				&& ++j)
				;
		if (!(table->cmd + 1)[i][j] && j > 1)
			i++;
		else
			break ;
	}
	j = i;
	while ((table->cmd + 1)[j])
	{
		ft_putstr_fd((table->cmd + 1)[j++], 1);
		if ((table->cmd + 1)[j])
			ft_putchar_fd(' ', 1);
	}
	if (i == 0)
		ft_putchar_fd('\n', 1);
}
