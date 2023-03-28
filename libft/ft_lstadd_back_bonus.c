/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:54 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 13:54:38 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst)
		return ;
	if (!lst[0])
		lst[0] = new;
	else
	{
		t = lst[0];
		while (t->next)
		{
			t = t->next;
		}
		t->next = new;
	}
}
