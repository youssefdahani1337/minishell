/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:07:21 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 22:44:18 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_pwd(t_cmdtable *table)
{
	char	pwd[MAXPATHLEN];

	if (!getcwd(pwd, MAXPATHLEN))
	{
		ft_perr_sts();
		return ;
	}
	ft_putstr_fd(pwd, table->out->fd);
	ft_putchar_fd('\n', table->out->fd);
}
