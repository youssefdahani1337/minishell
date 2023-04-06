/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:20:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/02 15:54:53 by hbenabad         ###   ########.fr       */
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

void	ft_exit(void)
{
	char	**str;
	int		k;
	int		valid;

	k = 0;
	str = g_shell.table->cmd + 1;
	if (str[0] == NULL)
	{	ft_putstr_fd("exit\n", 1);
		// free struct
		exit(g_shell.exitsts);
	}
	while (str[k])
		k++;
	valid = ft_check_valid(str[0]);
	if (valid == -1)
	{
		ft_putstr_fd("exit\nnumeric argument required\n", 2);
		// free struct
		exit (255);
	}
	else if (valid > -1)
	{
		if (k == 1)
		{
			// free struct
			exit(valid);
		}
		else
		{
			ft_putstr_fd("exit\ntoo many arguments\n", 2);
			g_shell.exitsts = 1;
		}
	}
}
