/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:11:27 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/08 10:45:35 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_exit_msg(char *fstparam, char *str, int exitsts)
{
	g_shell.exitsts = exitsts;
	printf("exit\n");
	if (str)
	{
		if (fstparam)
			printf("minishell: exit: %s: %s\n", fstparam, str);
		else
		{
			printf("minishell: exit: %s\n", str);
			return ;
		}
	}
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
