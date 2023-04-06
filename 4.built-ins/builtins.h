/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:19 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include "../include/structs.h"
# include "../libft/libft.h"

void	ft_change_pwds(t_env *p, char *opwd, int to_print, t_shell *gn_shell);
char	*ft_find_opwd(t_env *p);
void	ft_cd(t_shell *gn_shell);
int		ft_flag_ignore(char **str);
void	ft_echo(void);
void	ft_envclear(t_env **lst);
int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
int		ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_env_fill(char **env);
void	ft_env(void);
void	ft_rank_lst(t_list **keylst);
void	ft_ranker(t_env *env_info, t_list **keys_lst);
void	ft_rank_env(t_env *env_info);
void	ft_export(void);
void	ft_pwd(void);
void	ft_msgexitsts(char *str, int errnum);
void	ft_delnode(t_env *p, int i);
void	ft_unset(void);
int		ft_check_valid(char	*str);
void	ft_exit(void);

#endif
