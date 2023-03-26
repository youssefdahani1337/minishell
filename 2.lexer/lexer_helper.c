/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:27:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 12:26:30 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer_iter(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < lexer->size)
	{
		lexer->i ++;
		lexer->c = lexer->src[lexer->i];
	}
}
void		ft_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c != '\0' && ft_strchr(" \t\n", lexer->c))
		lexer_iter(lexer);
}

t_tokens	*lexer_forward(t_lexer *lexer, char *value, int type, int join)
{
	lexer_iter(lexer);
	return (ft_newtoken(value, type, join));
}

t_tokens	*lexer_advance(t_lexer *lexer, t_tokens *token)
{
	lexer_iter(lexer);
	return (token);
}

t_tokens	*ft_exit_lexer(t_tokens **t, char *line, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_cleartoken(*t);
	*t = NULL;
	system("leaks minishell");
	free(line);
	return (NULL);
}

int			next_quote_str(t_lexer *lexer)
{
	unsigned int	i;

	i = lexer->i;
	if (i + 1 < lexer->size)
	{	
		i ++;
		if (!ft_strchr(" |<>", lexer->src[i]))
			return (2);
	}
	return (0);	
}

int			previous_quote_str(t_lexer *lexer)
{
	unsigned int	i;

	i = lexer->i;
	if (i != 0)
	{	
		i --;
		if (!ft_strchr(" |<>", lexer->src[i]))
			return (1);
	}
	return (0);
}