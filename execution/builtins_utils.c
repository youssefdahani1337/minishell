/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/28 17:23:48 by hbenabad         ###   ########.fr       */
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

void	ft_change_pwds(t_env *p, char *opwd, char *pwd)
{
	int	cmp_p;
	int	cmp_op;

	cmp_p = 1;
	cmp_op = 1;
	while (p)
	{
		if (cmp_op != 0)
		{
			cmp_op = ft_strncmp (p->key, "OLDPWD", ft_strlen(p->key));
			if (cmp_op == 0)
				p->value = opwd;
		}
		else if (cmp_p != 0)
		{
			cmp_p = ft_strncmp(p->key, "PWD", ft_strlen(p->key));
			if (cmp_p == 0)
				p->value = pwd;
		}
		p = p->next;
	}
}
