/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sanitizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:10:47 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/12 12:59:58 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

static char	get_t(char c)
{
	if (c == red_in)
		return (herdoc);
	return (red_app);
}

t_tokens	*lexer_str(t_lexer *lexer)
{
	char	*value;

	value = ft_strdup("");
	while (lexer->c != '\0' && !ft_strchr(" <>|'\"", lexer->c))
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, string));
}

t_tokens	*lexer_red(t_lexer *lexer)
{
	char		type;

	type = lexer->c;
	lexer_iter(lexer);
	if (type == lexer->c)
	{
		lexer_iter(lexer);
		return (ft_newtoken(NULL, get_t(type)));
	}
	return (ft_newtoken(NULL, type));
}

t_tokens	*lexer_quote(t_lexer *lexer)
{
	char	c;
	char	*value;

	value = ft_strdup("");
	c = lexer->c;
	lexer_iter(lexer);
	while (lexer->c != c)
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, c));
}
