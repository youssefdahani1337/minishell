/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:17:21 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 14:20:18 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

t_env	*ft_getenv(char *key)
{
	t_env	*ptr;

	ptr = g_shell.env;
	while (ptr)
	{
		if (!ft_strcmp(ptr->key, key))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
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
