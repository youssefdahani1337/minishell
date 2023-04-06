/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:31:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/05 01:33:41 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	ft_parser(t_parser **parser, t_tokens *token)
{
	parser_parse(parser, token);
	if (!open_heredoc(*parser))
		return (0);
	return (1);	
}
void	parser_parse(t_parser **parser, t_tokens *token)
{
	int	error;

	error = 1;
	while (token->type != terminator && error)
	{
		if (token->type == herdoc)
			parser_add_herdoc(parser, &token, &error);
		// if (token->type == red_app)
		// 	parser_add(parser, &token, limiter, &error);
		// if (token->type == red_out)
		// 	parser_add(parser, &token, limiter, &error);
		// if (token->type == red_in)
		// 	parser_add(parser, &token, limiter, &error);
		// if (token->type == pip)
		// 	parser_add(parser, &token, limiter, &error);
		// else
		// 	parser_add(parser, &token, limiter, &error);
	}
	ft_parseadd_back(parser, ft_newparse(NULL, p_terminator, 0));
}

