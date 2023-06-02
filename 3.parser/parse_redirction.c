/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:52:13 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/29 15:49:27 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void		parser_add_redirect(t_parser **parser, t_tokens **token, int *error)
{
	char	*value;
	int		type;
	int		var;
	int		state;

	// rev
	state = 0;
	value = ft_strdup("");
	var = 0;
	type = get_typeparse(*token);
	(*token) = (*token)->next;
	skipper_token(token);
	if (!in_join((*token)->type, &state))
	{
		*error = 0;
		ft_parseadd_back(parser, ft_newparse(NULL, p_error, 0));
		print_error("syntax error near unexpected token ", (*token)->value);
		return ;
	}
	while ((*token)->type != terminator && in_join((*token)->type, &var))
	{
		value = join_red(value, *token, &state);
		(*token)->value = NULL;
		(*token) = (*token)->next;
	}
	ft_parseadd_back(parser, ft_newparse(value, type, state));
}
char	*join_red(char *value, t_tokens *token, int *state)
{
	if (token->type == d_qoute)
		value = ft_strjoin_m(value, ft_exp(token->value, NULL));
	else if (token->type == s_qoute)
		value = ft_strjoin_m(value, token->value);
	else if (token->type == string)
		value = ft_join_exp(value, token->value, state);
	return(value);
}

char	*ft_join_exp(char *value, char *tok_str, int *state)
{
	char	**sp;

	tok_str = ft_exp(tok_str, NULL);
	sp = ft_split(tok_str, ' ');
	if (!sp || !sp[0])
		*state = -1;
	else if (count_sp(sp) > 1)
		*state = -1;
	free_sp(sp);
	return (ft_strjoin_m(value, tok_str));
	
}




