/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:02:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 11:34:45 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

void	ft_cmd_change(char **cmd)
{
	int		i;
	t_env 	*cmd_saver;

	i = 0;
	cmd_saver = ft_getenv("_");
	if (!cmd_saver)
	{
		//ft_env_addback(&g_shell.env, ft_envnew("_", cmd[0]));
		return ;
	}
	if (cmd_saver->value)
		free(cmd_saver->value);
	if (!cmd || !cmd[0])
		cmd_saver->value = NULL;
	else
	{
		while (cmd[i])
		{
			if (!cmd[i + 1])
				cmd_saver->value = ft_strdup(cmd[i]);
			i++;
		}
	}
	return ;
}
// void	ft_env_save(t_env *envlst)
// {
// 	int		env_size;
// 	char	**env_save;

// 	env_size = ft_env_size(g_shell.env);
// 	env_save = malloc(sizeof(char *) * (env_size + 1));
// 	while (envlst)
// 	{
// 		if (envlst->equal == 1)
// 		{
// 			ft_strjoin_m()
// 		}
// 	}
// }
