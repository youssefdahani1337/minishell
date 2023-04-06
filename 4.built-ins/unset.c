/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:06:04 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/02 09:58:23 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_delnode(t_env *p, int i)
{
	t_env	*unset;

	unset = NULL;
	if (i == 0)
	{
		unset = g_shell.env;
		g_shell.env = g_shell.env->next;
	}
	else if (i == 1)
	{
		unset = p->next;
		p->next = unset->next;
	}
	unset->next = NULL;
	free(unset->key);
	free(unset->value);
	free(unset);
}

void	ft_unset(void)
{
	char	**str;
	t_env	*p;
	int		k;

	str = g_shell.table->cmd + 1;
	k = 0;
	while (str[k])
	{
		p = g_shell.env;
		if (!ft_strcmp(p->key, str[k]))
			ft_delnode(p, 0);
		else
		{
			while (p)
			{
				if (!ft_strcmp((p->next)->key, str[k]))
				{
					ft_delnode(p, 1);
					break ;
				}
				p = p->next;
			}
		}
		k++;
	}
}
