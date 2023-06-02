/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/28 15:26:32 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H
ç

// void	ft_change_pwds(t_env *p, char *opwd, int to_print, t_shell *gn_shell);
void	ft_change_pwds(t_env *p, char *opwd, int to_print);
char	*ft_find_opwd(t_env *p);
// t_env	*ft_find_opwd(t_env *p);
// void	ft_cd(t_shell *gn_shell);
void	ft_cd(char **str, t_env *env);
int		ft_flag_ignore(char **str);
void	ft_echo(void);
void	ft_envclear(t_env **lst);
int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
int		ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_env_fill(char **env);
// void	ft_env(void);
void	ft_env(t_env *p);
void	ft_rank_lst(t_list **keylst);
void	ft_ranker(t_env *env_info, t_list **keys_lst);
void	ft_rank_env(t_env *env_info);
void	ft_export(void);
char	*ft_getpwd(t_env *ptr);
void	ft_pwd(void);
void	ft_msgexitsts(char *str, int status);
void	ft_delnode(t_env *p, int i);
void	ft_unset(void);
int		ft_check_valid(char	*str);
void	ft_exit(void);

#endif
