/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:24:45 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/10 15:47:58 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_newpwdval(char *pwd, char *opwd)
{
	t_env	*pwdnode;
	t_env	*opwdnode;
	char	*ptr;

	pwdnode = ft_getenv("PWD");
	if (pwdnode)
	{
		ptr = pwdnode->value;
		pwdnode->equal = 1; //test it
		pwdnode->value = pwd;
		if (ft_strcmp(ptr, opwd))
			free(ptr);
	}
	opwdnode = ft_getenv("OLDPWD");
	if (opwdnode)
	{
		ptr = opwdnode->value;
		opwdnode->equal = 1;
		opwdnode->value = opwd;
		free(ptr);
	}
	if (g_shell.unsetpwd == 1)
		g_shell.unsetpwd = 2;
	else if (g_shell.unsetpwd != 1 && !g_shell.opwd)
		g_shell.opwd = 2;
}

t_env	*ft_getenv(char *key)
{
	t_env	*ptr;

	ptr = g_shell.env;
	while (ptr)
	{
		if (!ft_strcmp(ptr->key, key))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

char	*ft_getopwd(int *oldp)
{
	char	opwd[MAXPATHLEN];
	t_env	*oldpwd;
	char	*opwd_val;

	if (!g_shell.unsetpwd)
	{
		oldpwd = ft_getenv("PWD");
		if (oldpwd)
			opwd_val = oldpwd->value;
	}
	if (g_shell.unsetpwd >= 2 || (!oldpwd && !g_shell.unsetpwd))// the first cd after unset done now it should get it from getcwd
	{
		if (!getcwd(opwd, MAXPATHLEN))
		{
			perror("minishell");
			*oldp = 0;
			return (NULL);
		}
		return (ft_strdup(opwd));
	}
	else if (1 == g_shell.unsetpwd) //just did unset test:(unset PWD cd . cd .) add in export if (export PWD=) unsetpwd = 0; 
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
		{
			printf("minishell: cd: %s not set\n", str);
			g_shell.exitsts = 1;
		}
		else if (direc[0] == '~' && (direc[1] && direc[1] == '/'))
			dir = ft_strjoin_m(dir, direc + 1);
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
	dir = ft_getdir(*(table->cmd + 1), &print);
	if (!dir)
		return ;
	opwd = ft_getopwd(&oldp);
	if (!oldp || (dir[0] && chdir(dir) == -1) || !getcwd(pwd, MAXPATHLEN))
	{
		if (oldp)
			perror("minishell");
		g_shell.exitsts = 1;
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
