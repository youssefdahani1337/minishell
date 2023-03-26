/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 12:12:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include "../1.tokenizer/token.h"

typedef	struct	s_lexer
{
	char			*src;
	unsigned int	i;
	char			c;
	size_t			size;
}	t_lexer;

t_lexer		*init_lexer(char *line);
void		ft_lexer( char *line, t_tokens **token);
t_tokens	*ft_next_token(t_lexer *lexer);

void		lexer_iter(t_lexer *lexer);
void		ft_skip_whitespace(t_lexer *lexer);
t_tokens	*lexer_forward(t_lexer *lexer, char *value, int type, int join);
t_tokens	*ft_exit_lexer(t_tokens **t, char *line, char *msg);

t_tokens	*ft_lexer_str(t_lexer *lexer);
t_tokens	*lexer_red(t_lexer *lexer);
t_tokens	*lexer_advance(t_lexer *lexer, t_tokens *token);

t_tokens	*lexer_quote(t_lexer *lexer);

int			previous_quote_str(t_lexer *lexer);
int			next_quote_str(t_lexer *lexer);
#endif