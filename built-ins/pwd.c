/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:07:21 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/30 18:12:48 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_pwd(t_cmdtable *cmd)
{
	char	pwd[MAXPATHLEN];

	if (!getcwd(pwd, MAXPATHLEN))
	{
		perror("minishell");
		return ;
	}
	ft_putstr_fd(pwd, cmd->out->fd);
	ft_putchar_fd('\n', cmd->out->fd);
}