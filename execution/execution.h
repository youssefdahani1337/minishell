/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/27 14:09:16 by yodahani         ###   ########.fr       */
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
t_env	*ft_env(char **env);

#endif
