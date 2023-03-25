/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:28 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/21 18:08:50 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_lexer(char *line, t_tokens **t)
{
	int			i;
	int			start;

	i = 0;
	start = 0;
	while (line[i])
	{
		while (line[i] == 32 && ++i)
			start ++;
		if (ft_strchr("$|\"'<>", line[i]))
		{
			join_str(t, line, start, i - start);
			if (line[i] == pip && ++i)
				ft_tokenadd_back(t, ft_newtoken(NULL, pip, 0));
			else if (ft_strchr("><", line[i]))
				ft_red_find(t, line, &i);
			else if (ft_strchr("\"'", line[i]))
				ft_quote_find(t, line, &i);
			else if (line[i] == var)
				ft_var_find(t, line, &i);
		}
		else
			i ++;
	}
}

void	ft_exit_lexer(t_tokens **t, char *line, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_cleartoken(*t);
	free(line);
	exit(1);
}
