/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 12:20:47 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executils.h"

void	ft_env(t_cmdtable *table);

void	ft_echo(t_cmdtable *table);
char	*ft_getopwd(int *oldp);
char	*ft_getdir(char *direc, int *print);
void	ft_cd(t_cmdtable *table);
void	ft_pwd(t_cmdtable *table);

void	ft_delenvnode(t_env *to_unset);
void	ft_unset(t_cmdtable *table);
void	ft_exit(t_cmdtable *table);

int		ft_isbuiltins(t_cmdtable *table);

void	ft_export(t_cmdtable *table);
t_list	*ft_keyslst(t_env *getkeys);
void	ft_rank_lst(t_list **keys);
void	ft_rank(t_list **keys);
void	ft_rank_env(void);
void	ft_export_display(t_env *leader, int out);
void	ft_changeadd_export(char **arg);
int		ft_changeadd(t_lexer *lexer, t_export *infos);
char	*find_key(t_lexer *lexer);
char	find_type_exp(t_lexer *lexer);
void	init_infos(t_export *infos);
void	free_infos(t_export *infos);
char	*find_value(t_lexer *lexer, t_export *infos);
#endif