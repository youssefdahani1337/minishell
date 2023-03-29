/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:11:13 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/29 16:33:21 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_pwd(void)
{
	char	path[128];
	char	*pwd;

	getcwd(path, 128);
	if (pwd == NULL)
		perror("getcwd:");
	ft_putstr_fd(pwd, g_shell.table->outfile);
	ft_putstr_fd("\n", g_shell.table->outfile);
}
