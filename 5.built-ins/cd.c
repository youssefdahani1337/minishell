/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:24:45 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 11:33:20 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_newpwdval(char *pwd, char *opwd)
{
	t_env	*pwdnode;
	t_env	*opwdnode;

	pwdnode = ft_getenv("PWD");
	if (pwdnode)
	{
		if (pwdnode->value)
			free(pwdnode->value);
		pwdnode->equal = 1;
		pwdnode->value = pwd;
	}
	opwdnode = ft_getenv("OLDPWD");
	if (opwdnode)
	{
		if (opwdnode->value)
			free(opwdnode->value);
		opwdnode->equal = 1;
		opwdnode->value = opwd;
	}
	if (!pwdnode)
		free(pwd);
	if (!opwdnode)
		free(opwd);
	if (g_shell.unsetpwd == 1)
		g_shell.unsetpwd = 2;
}

char	*ft_getopwd(int *oldp)
{
	char	opwd[MAXPATHLEN];
	char	*opwd_val;

	if (!g_shell.unsetpwd)
		opwd_val = get_env_val("PWD");
	if (g_shell.unsetpwd >= 2 || (!g_shell.unsetpwd && !opwd_val))
	{
		if (!getcwd(opwd, MAXPATHLEN))
		{
			*oldp = 0;
			return (NULL);
		}
		opwd_val = ft_strdup(opwd);
	}
	else if (1 == g_shell.unsetpwd)
		opwd_val = NULL;
	*oldp = 1;
	return (opwd_val);
}

char	*ft_getdir(char *direc, int *print)
{
	char	*str;
	char	*dir;

	str = NULL;
	if (!(direc) || (direc[0] == '~' && (!direc[1] || direc[1] == '/')))
		str = "HOME";
	else if (!ft_strcmp(direc, "-")) 
	{
		str = "OLDPWD";
		*print = 1;
	}
	if (str)
	{
		dir = get_env_val(str);
		if (!dir)
			ft_errmsg_sts("minishell: cd: ", str, " not set\n");
		else if (direc && direc[0] == '~' && (direc[1] && direc[1] == '/'))
			dir = ft_strjoin_m(dir, ft_strdup(direc + 1));
	}
	else
		dir = ft_strdup(direc);
	return (dir);
}	

void	ft_cd(t_cmdtable *table)
{
	char	*dir;
	int		oldp;
	int		print;
	char	*opwd;
	char	pwd[MAXPATHLEN];

	print = 0;
	if (table->cmd[1] && !table->cmd[1][0])
		dir = ft_strdup(".");
	else
		dir = ft_getdir(table->cmd[1], &print);
	if (!dir)
		return ;
	opwd = ft_getopwd(&oldp);
	if (!oldp || (dir[0] && chdir(dir) == -1) || !getcwd(pwd, MAXPATHLEN))
	{
		free(dir);
		free(opwd);
		ft_perr_sts();
		return ;
	}
	if (print == 1)
	{
		if (dir[0])
			ft_putstr_fd(pwd, table->out->fd);
		ft_putchar_fd('\n', table->out->fd);
	}
	free(dir);
	ft_newpwdval(ft_strdup(pwd), opwd);
}
