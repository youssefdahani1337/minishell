/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:57:05 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/01 15:01:59 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_flag_ignore(char **str)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	end = 1;
	while (str[i] && end == 1)
	{
		j = 0;
		if (str[i][j] && str[i][j] == '-')
		{
			j++;
			while (str[i][j] && str[i][j] == 'n')
				j++;
			if (!str[i][j] && j > 1)
				i++;
			else if (str[i][j] || (!str[i][j] && j <= 1))
				end = 0;
		}
		else
			end = 0;
	}
	return (i);
}

void	ft_echo(void)
{
	int		index;
	int		k;
	char	**str;
	int		out;

	out = g_shell.table->outfile->fd;
	str = g_shell.table->cmd + 1;
	index = ft_flag_ignore(str);
	k = index;
	while (str[k])
	{
		ft_putstr_fd(str[k], out);
		k++;
		if (str[k])
			ft_putstr_fd(" ", out);
	}
	if (index < 1)
		ft_putchar_fd('\n', out);
}
