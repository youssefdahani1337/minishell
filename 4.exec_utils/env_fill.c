/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:57:23 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 14:01:00 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

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
	}
	if (g_shell.opwd == 0)
	{
		if (!ft_envadd_back(&env_info, ft_envnew("OLDPWD")))
			return (NULL);
	}
	return (env_info);
}
