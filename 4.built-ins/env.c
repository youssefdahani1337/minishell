/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:19 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/29 16:43:49 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_env	*ft_env(char **env)
{
	int		i;
	int		j;
	int		opwd;
	t_env	*new;
	t_env	*env_info;

	i = 0;
	j = 0;
	opwd = 0;
	env_info = NULL;
	while (env[i])
	{
		new = ft_envnew(env[i]);
		if (ft_envadd_back(&env_info, ft_envnew(env[i])) == 0)
			return (NULL);
		if (ft_strncmp(new->key, "OLDPWD", 7) == 0)
			opwd = 1;
		i++;
	}
	if (opwd == 0)
	{
		if (ft_envadd_back(&env_info, ft_envnew("OLDPWD")) == 0)
			return (NULL);
	}
	return (env_info);
}
