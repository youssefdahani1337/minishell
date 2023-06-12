/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:28 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/12 13:10:45 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_lexer	*init_lexer(char *line)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->src = line;
	lexer->size = ft_strlen(line);
	lexer->i = 0;
	lexer->c = lexer->src[lexer->i];
	return (lexer);
}

int	ft_lexer(char *line, t_tokens **token)
{
	t_lexer		*lexer;
	t_tokens	*t;

	lexer = init_lexer(line);
	if (!lexer)
		return (0);
	if (!lexer_syntax(lexer))
		return (0);
	lexer = init_lexer(line);
	t = ft_next_token(lexer);
	while (t && t->type != terminator)
	{
		ft_tokenadd_back(token, t);
		t = ft_next_token(lexer);
	}
	ft_tokenadd_back(token, t);
	free_lexer(lexer);
	return (1);
}

t_tokens	*ft_next_token(t_lexer *lexer)
{
	while (lexer->c != 0)
	{
		if (!ft_strchr(" |<>'\"", lexer->c))
			return (lexer_str(lexer));
		if (lexer->c == space)
			return (lexer_space(lexer));
		if (lexer->c == pip)
			return (lexer_forward(lexer, ft_strdup("|"), pip));
		if (lexer->c == red_in || lexer->c == red_out)
			return (lexer_red(lexer));
		if (lexer->c == s_qoute || lexer->c == d_qoute)
			return (lexer_advance(lexer, lexer_quote(lexer)));
	}
	return (ft_newtoken(ft_strdup(""), terminator));
}

t_tokens	*lexer_space(t_lexer *lexer)
{
	ft_skip_whitespace(lexer);
	return (ft_newtoken(ft_strdup(" "), space));
}
