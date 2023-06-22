/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_adds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:35:53 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/21 22:15:28 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

int	count_sp(char **sp)
{
	int	i;

	i = 0;
	if (!sp)
		return (0);
	while (sp[i])
		i++;
	return (i);
}

void	free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}
