/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_sapce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:32:45 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/22 10:23:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	parser_add_string(t_parser **parser, t_tokens **token)
{
	t_lexer	*lexer;

	(*token)->value = ft_exp((*token)->value);
	lexer = init_lexer((*token)->value);
	while (lexer->c)
	{
		if (lexer->c != space)
			add_str_parse(parser, lexer);
		else
			add_space_parse(parser, lexer);
	}
	(*token) = (*token)->next;
	free(lexer);
}

void	add_str_parse(t_parser **parser, t_lexer *lexer)
{
	char	*value;

	value = ft_strdup("");
	while (lexer->c != '\0' && lexer->c != space)
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	ft_parseadd_back(parser, ft_newparse(value, p_string, 0));
}

void	add_space_parse(t_parser **parser, t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->c == space)
		lexer_iter(lexer);
	ft_parseadd_back(parser, ft_newparse(NULL, p_space, 0));
}

void	parser_add_quote(t_parser **parser, t_tokens **token)
{
	if ((*token)->type == d_qoute)
		ft_parseadd_back(parser,
			ft_newparse(ft_exp((*token)->value), p_string, 0));
	else
		ft_parseadd_back(parser, ft_newparse((*token)->value, p_string, 0));
	(*token)->value = NULL;
	(*token) = (*token)->next;
}

void	add_parse(t_parser **parser, t_tokens **token)
{
	int		type;
	char	*value;

	value = ft_strdup((*token)->value);
	type = get_typeparse(*token);
	if ((*token)->type == pip)
		g_shell.exitsts = 0;
	(*token) = (*token)->next;
	ft_parseadd_back(parser, ft_newparse(value, type, 0));
}
