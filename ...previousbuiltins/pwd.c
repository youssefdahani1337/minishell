/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:11:13 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/26 12:52:30 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_getpwd(t_env *ptr)
{
	while (ptr)
	{
		if (!ft_strcmp(ptr->key, "PWD"))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

// void	ft_pwd(void)
// {
// 	char	pwd[128];
// 	int		i;
// 	int		out;
// 	char	**str;

// 	i = 0;
// 	str = g_shell.table->cmd;
// 	out = g_shell.table->outfile;
// 	if (!getcwd(pwd, 128))
// 	{
// 		pwd = ft_getpwd(g_shell.env);
// 		if (!pwd)
// 		{
// 			ft_putstr_fd("path not found", out);
// 			g_shell.exitsts = errno;
// 			return ;
// 		}
// 	}
// 	ft_putstr_fd(pwd, out);
// 	ft_putchar_fd("\n", out);
// }
