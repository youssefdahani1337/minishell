/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:02:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 20:29:24 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

void	ft_cmd_change(char **cmd)
{
	int		i;
	t_env 	*cmd_saver;
	char	*l_cmd;

	i = -1;
	l_cmd = NULL;
	while (cmd && cmd[++i])
	{
		if (!cmd[i + 1])
			l_cmd = ft_strdup(cmd[i]);
	}
	cmd_saver = ft_getenv("_");
	if (!cmd_saver)
	{
		cmd_saver = ft_envnew("_");
		ft_envadd_back(&g_shell.env, cmd_saver);
	}
	else if (cmd_saver->value)
		free(cmd_saver->value);
	cmd_saver->value = l_cmd;
	cmd_saver->equal = 1;
	return ;
}
