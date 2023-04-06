/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:18:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/01 15:56:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	ft_parser(t_parser **p, t_tokens **t)
{
	if (check_red(p, *t) == 0)
		return (0);
	ft_heredoc(*p);
	return (1);
}

