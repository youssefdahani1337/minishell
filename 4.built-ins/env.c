/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:14:53 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/21 22:03:36 by hbenabad         ###   ########.fr       */
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

t_env	*newenv(t_export *ex)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (env);
	env->key = ex->key;
	env->value = ex->value;
	env->equal = ex->type;
	env->next = NULL;
	return (env);
}
