/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/07 18:46:15 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/param.h>
# include "../libft/libft.h"
# include "../include/structs.h"
# include <readline/readline.h>
# include <readline/history.h>

void	ft_envclear(t_env **lst);
int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
int		ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_env_fill(char **env);
void	ft_env(t_cmdtable *table);

void	ft_echo(t_cmdtable *table);
t_env	*ft_getenv(char *key);
char	*ft_getopwd(int *oldp);
char	*ft_getdir(char *direc, int *print);
void	ft_cd(t_cmdtable *table);
void	ft_pwd(t_cmdtable *table);

void	ft_delenvnode(t_env *to_unset);
void	ft_unset(t_cmdtable *table);
void	ft_exit(t_cmdtable *table);

#endif