/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:09:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 10:06:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "debug.h"

void	printparser(t_parser *parser)
{
	printf("value[%s]\t", parser->value);
	printf("value[%d]\t", parser->state);
	switch (parser->type)
	{
		case limiter:
			printf("limiter\n");
			break;
		case infile:
			printf("infile\n");
			break;
		case outfile:
			printf("outfile\n");
			break;
		case appfile:
			printf("appfile\n");
			break;
		case p_string:
			printf("p_string\n");
			break;
		case p_pip:
			printf("p_pip\n");
			break;
		case p_error:
			printf("error\n");
			break;
		case p_space:
			printf("space\n");
			break;
		case p_terminator:
			printf("Terminatorr\n");
			break;

	}
	
}
void	print_parser_iter(t_parser *parser)
{
	while (parser)
	{
		printparser(parser);
		parser = parser->next;
	}
}