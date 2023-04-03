/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/02 15:18:01 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_parser	*parser;

	parser = NULL;
	token = NULL;
	if (!ft_lexer(line, &token))
		return (0);
	while (token)
	{
		printtoken(token);
		token = token->next;
	}
	return (1);
}
