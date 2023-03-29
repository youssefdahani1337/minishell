/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/29 16:41:00 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H
# include <stdio.h>
# include <stdlib.h>
# include "../include/structs.h"
# include "../libft/libft.h"

void	ft_change_pwds(t_env *p, char *opwd, char *pwd);
void	ft_cd(void);
int		ft_flag_ignore(char **str);
void	ft_echo(void);
void	ft_envclear(t_env **lst);
int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
int		ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_env(char **env);
void	ft_rank_lst(t_list **keylst);
void	ft_ranker(t_env *env_info, t_list **keys_lst);
int		ft_rank_env(t_env *env_info);
void	ft_export(void);
void	ft_pwd(void);

#endif
