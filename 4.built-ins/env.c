/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:19 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/29 17:15:33 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_env	*ft_env_fill(char **env)
{
	int		i;
	int		opwd;
	t_env	*new;
	t_env	*env_info;

	i = 0;
	opwd = 0;
	env_info = NULL;
	if (env)
	{
		while (env[i])
		{
			new = ft_envnew(env[i++]);
			if (ft_envadd_back(&env_info, new) == 0)
				return (NULL);
			if (ft_strncmp(new->key, "OLDPWD", 7) == 0)
				opwd = 1;
		}
		if (opwd == 0)
		{
			if (ft_envadd_back(&env_info, ft_envnew("OLDPWD")) == 0)
				return (NULL);
		}
	}
	return (env_info);
}

void	ft_env(t_env *p)
{
	// t_env	*p;

	// p = g_shell.env;
	while (p)
	{
		if (p->equal == 1)
		{
			ft_putstr_fd(p->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(p->value, 1);
			ft_putchar_fd('\n', 1);
		}
		p = p->next;
	}
}
