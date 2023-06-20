

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	int				equal;
	struct s_env	*follow;
	struct s_env	*next;
}	t_env;

typedef struct s_file
{
	int				fd;
	char			*error;
	struct s_file	*next;
}	t_file;

typedef struct s_cmdtable
{
	char				**cmd;
	t_file				*in;
	t_file				*out;
	pid_t				pid;
	int					**pipe;
	struct s_cmdtable	*next;
}	t_cmdtable;

typedef struct s_shell
{
	t_env		*env;
	t_cmdtable	*table;
	t_env		*leader;
	int			exitsts;
	int			unsetpwd;
	int			opwd;
	char		**env_save;
}	t_shell;

t_shell g_shell;

#endif