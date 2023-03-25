/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:57:05 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/25 14:55:16 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**ft_fill_infos(char **infos, char *str, int len)
{
	infos[0] = malloc(sizeof(char) * (len + 1));
	if (!infos[0])
		return (ft_free(infos), NULL);
	if (!str[len])
	{
		infos[1] = NULL;
		infos[2] = NULL;
	}
	else if (str[len])
	{
		infos[1] = malloc(sizeof(char) * 2);
		if (!infos[1])
			return (ft_free(infos), NULL);
		infos[1] = "=";
		infos[2] = malloc(sizeof(char) * (ft_strlen(str + len + 1) + 1));
		if (!infos[2])
			return (ft_free(infos), NULL);
		infos[2] = str + len + 1;
	}
	return(infos);
}

char	**ft_infos(char *str)
{
	int		i;
	char	**infos;

	i = 0;
	infos = (char **)malloc(sizeof(char *) * 4);
	if (!infos)
		return (NULL);
	while (str[i] != '=' && str[i])
		i++;
	infos = ft_fill_infos(infos, str, i);
	return (infos);
}

t_env	*ft_envnew(char **infos, int i)
{
	t_env *lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (0);
	lst->var = infos[0];
	if (infos[1][0] == '=')
		lst->equal = 1;
	lst->value = infos[2];
	lst->rank = i;
	lst->next = NULL;
	return (lst);
}

t_env	*ft_envlast(t_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			last = ft_envlast(*lst);
			last -> next = new;
		}
	}
}
