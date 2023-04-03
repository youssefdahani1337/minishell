/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:00:54 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/02 15:32:27 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "minishell.h"

typedef	enum	e_type_p
{
	limiter,
	infile,
	outfile,
	appfile,
	p_string,
	p_pip,
}	t_type_p;

typedef	enum	e_state
{
	s_quote,
	d_quote,
	
}	t_state;

typedef struct s_parser
{
	t_type_p		type;
	t_state			state;
	char			*value;
	struct s_parser	*next;
}	t_parser;

int			ft_parser(t_tokens *toknes);
t_parser	*ft_newparse(char *value, int type);
void		ft_parseadd_back(t_parser **parser, t_parser *new);
void		ft_clearparse(t_parser *p);
void		free_parse(t_parser *p);



#endif