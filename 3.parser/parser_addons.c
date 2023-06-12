/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_addons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:42:39 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 09:55:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_parser	*ft_newparse(char *value, int type, int state)
{
	t_parser	*p;

	p = (t_parser *) malloc(sizeof(t_parser));
	if (!p)
		return (0);
	p->value = value;
	p->type = type;
	p->state = state;
	p->next = NULL;
	return (p);
}

void	ft_parseadd_back(t_parser **parser, t_parser *new)
{
	t_parser	*p;

	if (!parser)
		return ;
	if (!parser[0])
		parser[0] = new;
	else
	{
		p = parser[0];
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	ft_clearparse(t_parser *p)
{
	t_parser	*del;

	while (p)
	{
		del = p->next;
		free_parse(p);
		p = del;
	}
}

void	free_parse(t_parser *p)
{
	free(p->value);
	free(p);
}
