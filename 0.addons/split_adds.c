/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_adds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:35:53 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/23 18:26:42 by hbenabad         ###   ########.fr       */
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
	if (!sp)
		return ;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}

void	ft_free_dstr(char **sp, int size)
{
	int	i;

	i = 0;
	if (!sp)
		return ;
	while (i < size)
		free(sp[i++]);
	free(sp);
}
