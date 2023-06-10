/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:44:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 14:58:38 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	check_red(t_parser **p, t_tokens *t)
{
	t_tokens	*tmp;


	while (t)
	{
		tmp = t->next;
		if (t->type == herdoc && tmp && tmp->type == string)
			ft_parseadd_back(p, ft_newparse(open_herdoc(t->value),limiter))
		else if (in_redir(t->type))
		{

			if (tmp && tmp->type != string)
			{
				g_shell.exitsts = 258;
				return (print_error("parse error near", tmp->value));
			}
			else
				remove_redir(p, &t);
		}
		else if (t->type == string)
			ft_parseadd_back(p, ft_newparse(t->value, p_string));
		else
			ft_parseadd_back(p, ft_newparse(t->value, p_pip));
		t = t->next; 
	}
	return (1);
}

int	in_redir(int type)
{
	if (type == red_app || type == red_in || type == red_out || type == herdoc)
		return (1);
	return (0);
}

void	remove_redir(t_parser **p, t_tokens **t)
{
	t_tokens	*tmp;

	tmp = (*t)->next;
	 if (!tmp)
		ft_tokenadd_back(t, ft_newtoken(NULL, string, 0));
	if ((*t)->type == herdoc)
		ft_parseadd_back(p, ft_newparse(tmp->value, limiter));
	else if ((*t)->type == red_in)
		ft_parseadd_back(p, ft_newparse(tmp->value, infile));
	else if ((*t)->type == red_out)
		ft_parseadd_back(p, ft_newparse(tmp->value, outfile));
	else if ((*t)->type == red_app)
		ft_parseadd_back(p, ft_newparse(tmp->value, appfile));
	*t = (*t)->next; 
}