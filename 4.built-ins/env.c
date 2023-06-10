/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:14:53 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/08 10:35:29 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

t_env	*ft_env_fill(char **env)
{
	int		i;
	t_env	*new;
	t_env	*env_info;

	i = 0;
	env_info = NULL;
	if (env)
	{
		while (env[i])
		{
			new = ft_envnew(env[i++]);
			if (!ft_envadd_back(&env_info, new))
				return (NULL);
		}
		if (g_shell.opwd == 0)
		{
			if (!ft_envadd_back(&env_info, ft_envnew("OLDPWD")))
				return (NULL);
		}
	}
	return (env_info);
}

void	ft_env(t_cmdtable *table)
{
	t_env	*ptr;

	(void)table; // redirection to a file
	ptr = g_shell.env;
	while (ptr)
	{
		if (ptr->equal == 1)
		{
			if (ft_strcmp(ptr->key, "OLDPWD") || g_shell.opwd)
			{
				ft_putstr_fd(ptr->key, 1);
				ft_putchar_fd('=', 1);
				ft_putstr_fd(ptr->value, 1);
				ft_putchar_fd('\n', 1);
			}
		}
		ptr = ptr->next;
	}
	return ;
}
