/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:58:36 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 23:20:23 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTILS_H
# define EXECUTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/param.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "addons.h"
# include "expand.h"
# include "lexer.h"

typedef enum s_export_t
{
	no_equal,
	true_equal,
	equal= '=',
	p_equal = '+',
	exp_error
}	t_export_t;

typedef struct s_export
{
	char		*key;
	char		*value;
	t_export_t	type;
	t_env		*node;
}	t_export;

void	ft_errmsg_sts(char *cmd, char *str, char *err);
void	ft_perr_sts(void);
void	ft_pipes_msg(char *name, char *str, int exitsts);
void	ft_print_msg(char *str, int exitsts);
void	ft_envclear(t_env **lst);
int		ft_fillnew(t_env *new, char *str);
t_env	*ft_envnew(char *str);
t_env	*ft_envlast(t_env *lst);
int		ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_getenv(char *key);
t_env	*newenv(t_export *ex);
t_env	*ft_env_fill(char **env);
int		ft_envsize(t_env *env_ptr);
char	**ft_env_save(t_env *env_ptr);
int		ft_tablesize(t_cmdtable *table);
void	ft_freedptr(int **pipes, int size);
void	ft_cmd_change(char **cmd);
void	ft_cmd_change(char **cmd);
int		ft_shlvl(void);
int		ft_setpwd(void);

#endif