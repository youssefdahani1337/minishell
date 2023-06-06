/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:10 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/06 15:51:23 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_echo(t_cmdtable *cmd)
{
	int	i;
	int	j;

	i = 0;
	while ((cmd->cmd + 1)[i])
	{
		j = 0;
		if ((cmd->cmd + 1)[i][j] == '-' && ++j)
			while ((cmd->cmd + 1)[i][j] && (cmd->cmd + 1)[i][j] == 'n' && ++j)
				;
		if (!(cmd->cmd + 1)[i][j] && j > 1)
			i++;
		else
			break ;
	}
	j = i;
	while ((cmd->cmd + 1)[j])
	{
		ft_putstr_fd((cmd->cmd + 1)[j++], 1);
		if ((cmd->cmd + 1)[j])
			ft_putchar_fd(' ', 1);
	}
	if (i == 0)
		ft_putchar_fd('\n', 1);
}
