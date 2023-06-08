/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:17:44 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/01 17:00:54 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_envclear(t_env **lst)
{
	t_env	*t;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		free((*lst)->key);
		free((*lst)->value);
		free(*lst);
		*lst = t;
	}
	*lst = NULL;
}

int	ft_fillnew(t_env *new, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (!str[i])
	{
		new->equal = 0;
		new->value = 0;
	}
	else if (str[i])
	{
		new->equal = 1;
		new->value = ft_strdup(str + i + 1);
		if (!new->value)
			return (free(new), 0);
	}
	new->key = ft_substr(str, 0, i);
	if (!new->key)
		return (free(new->value), free(new), 0);
	return (1);
}

t_env	*ft_envnew(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	if (ft_fillnew(new, str) == 0)
		return (NULL);
	new->next = NULL;
	return (new);
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

int	ft_envadd_back(t_env **lst, t_env *new)
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
	if (!new)
		return (ft_envclear(lst), 0);
	return (1);
}
