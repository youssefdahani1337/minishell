/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:20:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/25 14:46:46 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_check_valid(char	*str)
{
	char	*save;
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	save = str + i;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(save));
}

void	ft_end(int valid)
{
	if (valid == -1)
	{
		ft_putstr_fd("exit\nnumeric argument required\n", 2);
		g_shell.exitsts = 255;
		exit (255);
	}
	else if (valid > -1)
	{
		if (i == 1)
		{
			g_shell.exitsts = valid;
			exit(valid);
		}
		else
		{
			ft_putstr_fd("exit\ntoo many arguments\n", 2);
			g_shell.exitsts = 1;
		}
	}
}

void	ft_exit(void)
{
	int		i;
	int		valid;

	i = 0;
	if (g_shell.table->cmd + 1 == NULL)
	{	
		ft_putstr_fd("exit\n", 1);
		exit(g_shell.exitsts);
	}
	while (str[i] && i < 2)
		i++;
	ft_end(ft_check_valid((g_shell.table->cmd + 1)[0]));
}
