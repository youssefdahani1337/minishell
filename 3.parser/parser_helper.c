/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:51:12 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/06 15:27:05 by yodahani         ###   ########.fr       */
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

void	parser_add_herdoc(t_parser **parser, t_tokens **token, int *error)
{
	int		state;
	char	*value;

	state = 0;
	(*token) = (*token)->next;
	skipper_token(token);
	if (!in_join((*token)->type, &state))
	{
		*error = 0;
		ft_parseadd_back(parser, ft_newparse(NULL, p_error, 0));
		print_error("syntax error near unexpected token ", (*token)->value);
		return ;
	}
	value = join_token(token, &state);
	ft_parseadd_back(parser, ft_newparse(value, limiter, state));
}

char	*join_token(t_tokens **token, int *state)
{
	char	*value;

	value = ft_strdup("");
	while ((*token)->type != terminator && in_join((*token)->type, state))
	{
		value = ft_strjoin_m(value, (*token)->value);
		(*token)->value = NULL;
		(*token) = (*token)->next;
	}
	return (value);
}

void	skipper_token(t_tokens **tokens)
{
	while ((*tokens)->type == space)
		(*tokens) = (*tokens)->next;
}

int	get_typeparse(t_tokens *token)
{
	if (token->type == pip)
		return (p_pip);
	if (token->type == red_in)
		return (infile);
	if (token->type == red_out)
		return (outfile);
	if (token->type == red_app)
		return (appfile);
	if (token->type == herdoc)
		return (limiter);
	if (token->type == string)
		return (p_string);
	if (token->type == terminator)
		return (p_terminator);
	if (token->type == space)
		return (p_space);
	return (p_terminator);
}
