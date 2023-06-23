/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:12:12 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 18:40:53 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

char	**ft_env_save(t_env *env_ptr)
{
	char	**env_save;
	char	**ptr;
	int		i;

	i = 0;
	env_save = malloc(sizeof(char *) * (ft_envsize(g_shell.env) + 1));
	if (!env_save)
		return (NULL);
	while (env_ptr)
	{
		if (env_ptr->equal == 1)
		{
			ptr = ft_strjoin(env_ptr->key, "=");
			if (!ptr)
				return (ft_free_dstr(env_save), NULL);
			env_save[i] = ft_strjoin_m(ptr, ft_strdup(env_ptr->value));
			if (!env_save[i])
				return (ft_free_dstr(env_save), NULL);
			i++;
		}
		env_ptr = env_ptr->next;
	}
	return (env_save);
}
