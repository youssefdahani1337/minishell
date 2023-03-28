/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/28 15:30:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

void	loop_join(t_tokens **t)
{
	t_tokens	*token;
	
	token = *t;  
	while (token)
	{
		if (token->join != 0)
		{
			join_token(token);
		}
		token = token->next; 
	}
}

void	join_token(t_tokens *token)
{
	t_tokens	*t;


	if (token->join == 1 || token->join == 3)
	{
		t = token; 
		token = token->previous;
		token->value = ft_strjoin_m(token->value, t->value);
		token->next = t->next;
		free(t);
	}
	if (token->join > 1)
	{
		t = token->next;
		token->value = ft_strjoin_m(token->value, t->value);
		if (t->join > 1)
		{
			t->next
		}
				
		token->next = t->next;
		free(t);
	}
}
