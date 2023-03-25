/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:44:47 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/25 17:01:59 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../sources/minishell.h"

char	**ft_infos(char *str);
t_env	*ft_envnew(char **infos, int i);
t_env	*ft_envlast(t_env *lst);
void	ft_envadd_back(t_env **lst, t_env *new);
char	**ft_fill_infos(char **infos, char *str, int len);
void	ft_free_dstr(char **str, int k);

#endif
