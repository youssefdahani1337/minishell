/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:35:46 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:07 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_rank_lst(t_list **keylst)
{
	t_list	*p;
	t_list	*q;
	char	*str;
	int		len;

	p = *keylst;
	len = ft_strlen(p->content);
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (ft_strncmp(p->content, q->content, len) > 0)
			{
				str = p->content;
				p->content = q->content;
				q->content = str;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void	ft_ranker(t_env *env_info, t_list **keys_lst)
{
	t_list	*p;
	int		i;
	int		done;
	int		len;

	while (env_info)
	{
		i = 0;
		p = *keys_lst;
		done = 0;
		len = ft_strlen(env_info->key);
		while (p && done == 0)
		{
			if (ft_strncmp(env_info->key, p->content, len) == 0)
			{
				env_info->rank = i;
				done = 1;
			}
			i++;
			p = p->next;
		}
		env_info = env_info->next;
	}
}

void	ft_rank_env(t_env *env_info)
{
	t_list	*keys_lst;
	t_env	*p;
	int		i;

	i = 0;
	p = env_info;
	keys_lst = NULL;
	while (p)
	{
		ft_lstadd_back(&keys_lst, ft_lstnew(p->key));
		i++;
		p = p->next;
	}
	ft_rank_lst(&keys_lst);
	ft_ranker(env_info, &keys_lst);
}

void	ft_export(void)
{
	int		i;
	int		done;
	t_env	*p;

	i = 0;
	done = 0;
	p = g_shell.env;
	ft_rank_env(p);
	while (p)
	{
		if (done == 0 && ft_strcmp(p->key, "_") == 0)
		{
			p = g_shell.env;
			i++;
			done = 1;
		}
		else if (p->rank == i)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(p->key, 1);
			if (p->equal == 1)
				ft_putstr_fd("=", 1);
			if (p->value != NULL)
			{
				ft_putchar_fd('"', 1);
				ft_putstr_fd(p->value, 1);
				ft_putchar_fd('"', 1);
			}
			ft_putstr_fd("\n", 1);
			p = g_shell.env;
			i++;
		}
		else
			p = p->next;
	}
}
