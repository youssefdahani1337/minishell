/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sanitizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:10:47 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/27 11:48:39 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_tokens	*ft_lexer_str(t_lexer *lexer)
{
	char	*value;

	value = malloc(sizeof(char));
	if (!value)
		return (NULL);
	value[0] = '\0';
	while (lexer->c != '\0' && !ft_strchr(" '\"<>|", lexer->c))
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, string, 0));
}

t_tokens	*lexer_red(t_lexer *lexer)
{
	unsigned	int	i;

	i = lexer->i + 1 ; 
	if (lexer->c == red_in)
	{
		if (i < lexer->size)
		{
			if (lexer->src[i] == red_in)
				return (lexer_iter(lexer), ft_newtoken(NULL, herdoc, 0));	
			return (ft_newtoken(NULL, red_in, 0));	
		}
			return (ft_newtoken(NULL, red_in, 0));
	}
	else
	{
		if (i < lexer->size)
		{
			if (lexer->src[i] == red_out)
				return (lexer_iter(lexer), ft_newtoken(NULL, red_app, 0));	
			return (ft_newtoken(NULL, red_out, 0));
		}
		return (ft_newtoken(NULL, red_out, 0));
	}
}

t_tokens	*lexer_quote(t_lexer *lexer)
{
	int			type;
	char		*value;
	int			join;

	join = previous_quote_str(lexer);
	type = lexer->c;
	value = ft_strdup("");
	lexer_iter(lexer);
	while (lexer->c != '\0' && lexer->c != type)
	{
		value = ft_join_char(value, lexer->c);		
		lexer_iter(lexer);
	}
	if (lexer->c == '\0')
		return(free(value), ft_newtoken(ft_strdup("Unclosed quote"),error ,0));
	join += next_quote_str(lexer);
	return(ft_newtoken(value, type, join));
}