/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:14:04 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/12 20:18:40 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

void	ft_pipes_msg(char *name, char *str, int exitsts)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	// free what is allocated (struct, globalvar, path)
	exit(exitsts);
}

int	ft_slash_dot(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == '/')
		return (1);
	while (cmd[i] == '.')
		i++;
	if (cmd[i] == '/')
		return (2);
	return (0);
}
