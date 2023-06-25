/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:22:49 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/25 01:09:33 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_parser	*parser;
	t_cmdtable	*table;

	table = NULL;
	parser = NULL;
	token = NULL;
	if (check_space(line))
		return (free(line), 1);
	if (!ft_lexer(line, &token))
		return (0);
	if (ft_parser(&parser, token))
		return (0);
	fill_struct(&table, parser);
	ft_execution(table);
	free_cmd(table);
	return (1);
}
