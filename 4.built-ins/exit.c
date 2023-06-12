/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:11:27 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/12 11:52:32 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_exit_msg(char *fstparam, char *str, int exitsts)
{
	g_shell.exitsts = exitsts;
	if (!str)
		ft_putstr_fd("exit\n", 1);
	else
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		if (fstparam)
		{
			ft_putstr_fd(fstparam, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		if (!fstparam)
			return ;
	}
	// free what is allocated (struct, globalvar, path)
	exit(exitsts);
}

void	ft_exit(t_cmdtable *table)
{
	int		i;
	int		nb;

	i = 0;
	while ((table->cmd + 1)[i])
		i++;
	if (i == 0)
		ft_exit_msg(NULL, NULL, g_shell.exitsts);
	nb = ft_atoi((table->cmd + 1)[0]);
	if (nb == -1)
		ft_exit_msg((table->cmd + 1)[0], "numeric argument required", 255);
	if (i == 1)
		ft_exit_msg(NULL, NULL, nb);
	else if (i > 1)
		ft_exit_msg(NULL, "too many arguments", 1);
	return ;
}
