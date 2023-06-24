/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:14:53 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 18:43:36 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_env(t_cmdtable *table)
{
	t_env	*ptr;

	ptr = g_shell.env;
	while (ptr)
	{
		if (ptr->equal == 1)
		{
			if (ft_strcmp(ptr->key, "OLDPWD") || g_shell.opwd)
			{
				ft_putstr_fd(ptr->key, table->out->fd);
				ft_putchar_fd('=', table->out->fd);
				ft_putstr_fd(ptr->value, table->out->fd);
				ft_putchar_fd('\n', table->out->fd);
			}
		}
		ptr = ptr->next;
	}
	return ;
}
