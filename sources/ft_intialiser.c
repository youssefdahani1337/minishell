/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:29:34 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/21 19:23:41 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_intialize_shell(t_shell **shell, char **env)
{
	*shell = malloc(sizeof(t_shell));
	if (!*shell)
		exit(0);
	(*shell)->env = ft_get_env(env);
}

t_env	*ft_get_env(char **env)
{
	char	**sp;
	int		i;
	int		j;
	t_env	*e;
	i = -1;
	sp = ft_split(env, '\n');
	if (!sp)
		return (NULL);
	while (sp[++i])
	{
		j = 0;
		while (sp[i][j] && sp[i][j] != '=')
			j++;
		e = 
	}
}