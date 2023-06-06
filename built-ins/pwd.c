/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:07:21 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/06 16:02:06 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_pwd(t_cmdtable *cmd)
{
	char	pwd[MAXPATHLEN];

	(void)cmd;
	if (!getcwd(pwd, MAXPATHLEN))
	{
		perror("minishell");
		return ;
	}
	ft_putstr_fd(pwd, 1);
	ft_putchar_fd('\n', 1);
}