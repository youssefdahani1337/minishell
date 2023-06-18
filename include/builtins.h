/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:48 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/18 22:15:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/param.h>
# include "addons.h"
# include "expand.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "lexer.h"

typedef enum s_export_t
{
	no_equal,
	equal= '=',
	p_equal = '+',
	exp_error
	
} t_export_t;

typedef struct s_export
{
	char		*key;
	char		*value;
	t_export_t	type;
	t_env		*node;
} t_export;
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

int		ft_isbuiltins(t_cmdtable *table);

void	ft_export(t_cmdtable *table);
t_env	*newenv(t_export *ex);

void	ft_display_export(t_cmdtable *cmd, t_env *p);
void	ft_changeadd_export(char **arg);
int		ft_changeadd(char *arg);
char	*find_key(t_lexer *lexer);
char	find_type_exp(t_lexer *lexer);

char	*find_value(t_lexer *lexer, t_export *infos);
#endif