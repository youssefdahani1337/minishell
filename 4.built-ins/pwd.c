/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:07:21 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/10 18:31:20 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_pwd(t_cmdtable *table)
{
	char	pwd[MAXPATHLEN];

	(void)table;
	if (!getcwd(pwd, MAXPATHLEN))
	{
		perror("minishell");
		g_shell.exitsts = 1;
		return ;
	}
	ft_putstr_fd(pwd, table->out->fd);
	ft_putchar_fd('\n', table->out->fd);
}
