/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:24:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/11 10:18:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

int	check_space(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32)
			return (0);
		i ++;
	}
	return (1);
}
