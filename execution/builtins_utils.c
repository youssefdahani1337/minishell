/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/27 12:55:18 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_flag_ignore(char **str)
{
	int	i;
	int	j;
	int	end;

	i = 1;
	end = 1;
	if (!str)
		return (0);
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
