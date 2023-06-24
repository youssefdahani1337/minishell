/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:57:23 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 22:12:56 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

int	ft_setpwd(void)
{
	char	pwd[MAXPATHLEN];
	t_env	*pwdnode;

	pwdnode = ft_envnew("PWD");
	if (!ft_envadd_back(&g_shell.env, pwdnode))
		return (0);
	if (!getcwd(pwd, MAXPATHLEN))
	{
		ft_perr_sts();
		return (0);
	}
	pwdnode->equal = 1;
	pwdnode->value = ft_strdup(pwd);
	if (!pwdnode->value)
	{
		ft_perr_sts();
		return (0);
	}
	return (1);
}

t_env	*ft_env_fill(char **env)
{
	int		i;
	t_env	*new;
	t_env	*env_info;

	i = 0;
	env_info = NULL;
	if (env)
	{
		while (env[i])
		{
			new = ft_envnew(env[i++]);
			if (!ft_envadd_back(&env_info, new))
				return (NULL);
		}
	}
	if (g_shell.opwd == 0)
	{
		if (!ft_envadd_back(&env_info, ft_envnew("OLDPWD")))
			return (NULL);
	}
	return (env_info);
}
