/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/28 18:18:22 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include "../include/structs.h"
# include "../libft/libft.h"

int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
void	ft_envclear(t_env **lst);
int		ft_envadd_back(t_env **lst, t_env *new);
int		ft_flag_ignore(char **str);
void	ft_change_pwds(t_env *p, char *opwd, char *pwd);
void	ft_export(t_env	*p);
void	ft_rank_lst(t_list **keylst);
int		ft_rank_env(t_env *p);

#endif
