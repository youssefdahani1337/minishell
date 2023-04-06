/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:5.pipes/pipes.h
/*   Created: 2023/04/03 10:05:19 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/03 10:06:36 by hbenabad         ###   ########.fr       */
=======
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/30 17:47:01 by yodahani         ###   ########.fr       */
>>>>>>> 0681aa5b2ff7ef3d68140a0de68f327762cc2923:execution/execution.h
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H

# define PIPES_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include "../include/structs.h"
# include "../libft/libft.h

<<<<<<< HEAD:5.pipes/pipes.h
#endif
=======
t_env	*ft_env(char **env);
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

void	ft_echo(char **str);

#endif
>>>>>>> 0681aa5b2ff7ef3d68140a0de68f327762cc2923:execution/execution.h
