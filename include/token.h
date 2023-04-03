/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/02 15:26:45 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_H
# define TOKEN_H
# include "addons.h"

typedef enum e_type
{
	pip = '|',
	space = ' ',
	red_in = '<',
	red_out = '>',
	d_qoute = '\"',
	s_qoute = '\'',
	red_app,
	herdoc,
	string,
	terminator,
}	t_type;

typedef struct s_tokens
{
	char			*value;
	t_type			type;
	int				exp;
	struct s_tokens	*previous;
	struct s_tokens	*next;
}		t_tokens;

void		ft_tokenadd_back(t_tokens **tokens, t_tokens *new);
t_tokens	*ft_newtoken(char *value, int type);
void		free_token(t_tokens *t);
void		free_lsttokens(t_tokens *t);
void		join_token(t_tokens *token);
void		ft_cleartoken(t_tokens *t);

#endif