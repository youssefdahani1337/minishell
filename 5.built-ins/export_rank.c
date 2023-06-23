/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:04:53 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 00:36:29 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

t_list	*ft_keyslst(t_env *getkeys)
{
	t_list	*keys;

	keys = NULL;
	while (getkeys)
	{
		ft_lstadd_back(&keys, ft_lstnew(getkeys->key));
		getkeys = getkeys->next;
	}
	return (keys);
}

void	ft_rank_lst(t_list **res)
{
	char	*swap;
	t_list	*ptr;
	t_list	*keys;

	keys = *res;
	while (keys)
	{
		ptr = keys->next;
		while (ptr)
		{
			if (ft_strcmp(keys->content, ptr->content) > 0)
			{
				swap = keys->content;
				keys->content = ptr->content;
				ptr->content = swap;
			}
			ptr = ptr->next;
		}
		keys = keys->next;
	}
}

void	ft_rank(t_list **keys)
{
	t_list	*ptr;
	t_env	*env_save;
	t_env	*lead;
	int		fst;

	fst = 0;
	ptr = *keys;
	while (ptr)
	{
		if (ft_strcmp(ptr->content, "_"))
		{
			env_save = g_shell.env;
			while (env_save && ft_strcmp(env_save->key, ptr->content))
				env_save = env_save->next;
			if (fst)
				lead->follow = env_save;
			if (!fst++)
				g_shell.leader = env_save;
			lead = env_save;
		}
		ptr = ptr->next;
	}
	lead->follow = NULL;
}

void	ft_rank_env(void)
{
	t_list	*keys;

	keys = ft_keyslst(g_shell.env);
	ft_rank_lst(&keys);
	ft_rank(&keys);
	ft_lstclear(&keys);
}

void	ft_export_display(t_env *leader, int out)
{
	while (leader)
	{
		ft_putstr_fd("declare -x ", out);
		ft_putstr_fd(leader->key, out);
		if (leader->equal == 1)
		{
			ft_putchar_fd('=', out);
			ft_putchar_fd('"', out);
			ft_putstr_fd(leader->value, out);
			ft_putchar_fd('"', out);
		}
		ft_putchar_fd('\n', out);
		leader = leader->follow;
	}
}
