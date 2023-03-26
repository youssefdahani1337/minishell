/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:35:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 13:25:00 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"


t_tokens	*ft_newtoken(char *value, int type, int join)
{
	t_tokens	*t;

	t = (t_tokens *) malloc(sizeof(t_tokens));
	if (!t)
		return (0);
	t->value = value;
	t->type = type;
	t->join = join;
	t->next = NULL;
	return (t);
}

void	ft_tokenadd_back(t_tokens **tokens, t_tokens *new)
{
	t_tokens	*t;

	if (!tokens)
		return ;
	if (!tokens[0])
		tokens[0] = new;
	else
	{
		t = tokens[0];
		while (t->next)
		{
			t = t->next;
		}
		t->next = new;
	}
}

void	ft_cleartoken(t_tokens *t)
{
	t_tokens	*del;

	while (t)
	{
		del = t->next;
		free_token(t);
		t = del;
	}
}

void	free_lsttokens(t_tokens *t)
{
	t_tokens	*del;

	while (t)
	{
		del = t->next;
		free_token(t);
		t = del;
	}
}

void	free_token(t_tokens *t)
{
	free(t->value);
	free(t);
}
