/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:11:13 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/01 16:53:19 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_pwd(void)
{
	char	pwd[128];
	int		i;
	int		out;
	char	**str;

	i = 0;
	str = g_shell.table->cmd;
	out = g_shell.table->outfile;
	getcwd(pwd, 128);
	ft_putstr_fd(pwd, out);
	ft_putstr_fd("\n", out);
}
