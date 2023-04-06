/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:51:12 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/05 01:18:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"


int	in_join(int type, int *state)
{
	if (type == d_qoute || type == s_qoute)
	{
		 ++(*state);
		return (1);
	}
	if (type == string)
		return (1);
	return (0);
}
#include "../debug/debug.h"
void	parser_add_herdoc(t_parser **parser, t_tokens **token, int *error)
{
	int		state;
	char	*value;

	value = ft_strdup("");
	state = 0;
	skipper_token(token);
	if (!in_join((*token)->type, &state))
	{
		*error = 0;
		ft_parseadd_back(parser, ft_newparse(NULL, p_error, 0));
		print_error("syntax error near unexpected token ", (*token)->value);
		return;
	}	
	while ((*token)->type != terminator && in_join((*token)->type, &state))
	{
		printtoken((*token));
		value = ft_strjoin_m(value, (*token)->value);
		*token = (*token)->next;
	}
		printf("Here\n");
	ft_parseadd_back(parser, ft_newparse(value, limiter, state));
}

void		skipper_token(t_tokens **tokens)
{
	(*tokens) = (*tokens)->next;
	while ((*tokens)->type == space)
		(*tokens) = (*tokens)->next;
}
