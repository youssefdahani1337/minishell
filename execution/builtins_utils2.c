/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:35:46 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/26 15:38:41 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_free_dstr(char **str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void	ft_rank_lst(t_list **keylst)
// {
// 	t_list	*p;
// 	t_list	*q;
// 	char	*str;
// 	int		len;

// 	p = *keylst;
// 	len = ft_strlen(p->content);
// 	while (p)
// 	{
// 		q = p->next;
// 		while (q)
// 		{
// 			if (ft_strncmp(p->content, q->content, len) > 0)
// 			{
// 				str = p->content;
// 				p->content = q->content;
// 				q->content = str;
// 			}
// 			q = q->next;
// 		}
// 		p = p->next;
// 	}
// }

// void	ft_ranker(t_env **env_info, t_list *keys_lst)
// {
// }

// void	ft_rank_env(t_env **env_info)
// {
// 	t_env	*p;
// 	t_list	*keys_lst;

// 	p = *env_info;
// 	keys_lst = NULL;
// 	while (p)
// 	{
// 		ft_lstadd_back(&keys_lst, ft_lstnew(p->key));
// 		p = p->next;
// 	}
// 	ft_rank_lst(&keys_lst);
// 	while (keys_lst)
// 	{
// 		printf("%s\n", keys_lst->content);
// 		keys_lst = keys_lst->next;
// 	}
// 	ft_ranker(env_info, keys_lst);
// }