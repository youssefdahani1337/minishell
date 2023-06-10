/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:19:03 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/08 18:43:09 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

void	ft_multipipes(t_cmdtable )
{
	char	*path_val;
	char	**path;

	path_val = get_env_val("PATH"); // verify if path doesn't exist
	if (path_val)
	{
		if (path_val[0] == ':')
		{
			path_val = ft_strjoin_m(ft_strdup("."), path_val);
			path = ft_split(path_val, ':');
		}
		else
			path = ft_modify_path(path_val);
		free(path_val);
	}
}
