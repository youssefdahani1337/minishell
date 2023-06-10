/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:31:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/09 15:40:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	ft_parser(t_parser **parser, t_tokens *token)
{
	int	status;

	status = 0;
	parser_parse(parser, token, &status);
	ft_cleartoken(token);
	if (status == 1)
		ft_clearparse(*parser);
	return (status);
}

void	parser_parse(t_parser **parser, t_tokens *token, int *status)
{
	while (token->type != terminator && *status == 0)
		parser_parsing(parser, &token, status);
	ft_parseadd_back(parser, ft_newparse(NULL, p_terminator, 0));
	open_heredoc(*parser, status);
}

void	parser_parsing(t_parser **parser, t_tokens **token, int *error)
{
	if ((*token)->type == string)
		parser_add_string(parser, token);
	else if ((*token)->type == d_qoute || (*token)->type == s_qoute)
		parser_add_quote(parser, token);
	else if ((*token)->type == herdoc)
		parser_add_herdoc(parser, token, error);
	else if ((*token)->type == red_app || (*token)->type == red_out)
		parser_add_redirect(parser, token, error);
	else if ((*token)->type == red_in)
		parser_add_redirect(parser, token, error);
	else if ((*token)->type == pip || (*token)->type == space)
		add_parse(parser, token);
	else if ((*token)->type == terminator)
		add_parse(parser, token);
}
