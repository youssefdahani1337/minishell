/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:47:23 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/30 12:02:12 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	main(int argc, char **argv, char **env)
{
	t_cmdtable	cmd;
	t_env 		*pwd;
	t_env		*opwd;

	(void)argc;
	cmd.cmd = argv + 1;
	g_shell.env = ft_env_fill(env);
	pwd = ft_getenv("PWD");
	opwd = ft_getenv("OLDPWD");
	if (pwd)
		printf("%s=%s\n", pwd->key, pwd->value);
	if (opwd)
		printf("%s=%s\n", opwd->key, opwd->value);
	ft_cd(&cmd);
	pwd = ft_getenv("PWD");
	opwd = ft_getenv("OLDPWD");
	if (pwd)
		printf("%s=%s\n", pwd->key, pwd->value);
	if (opwd)
		printf("%s=%s\n", opwd->key, opwd->value);
	return (0);
}