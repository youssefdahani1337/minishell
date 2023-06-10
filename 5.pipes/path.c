/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:59:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/10 15:16:52 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

char	**ft_modify_path(char *path_val)
{
	int		i;
	char	*path_val1;
	char	*path_valc;

	i = -1;
	while (path_val[++i])
	{
		if (path_val[i] == ':' && (path_val[i + 1] && path_val[i + 1] == ':'))
		{
			path_valc = path_val;
			path_val1 = ft_strjoin_m(ft_substr(path_valc, 0, i + 1), ft_strdup("."));
			path_val = ft_strjoin_m(path_val1, ft_strdup(path_valc + i + 1));
			free(path_valc);
			break;
		}
		else if (path_val[i] == ':' && !path_val[i + 1])
		{
			path_val = ft_strjoin_m(path_val, ft_strdup("."));
			break;
		}
	}
	return (ft_split(path_val, ':'));
}

char