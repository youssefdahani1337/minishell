

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	int				rank;
	int				equal;
	struct s_env	*next;
}	t_env;

typedef struct s_file
{
	int				fd;
	char			*error;
	struct s_file	*next;
}	t_file;

typedef struct	s_cmdtable
{
	char				**cmd;
	t_file				*in;
	t_file				*out;
	struct s_cmdtable	*next;
}	t_cmdtable;

typedef struct	s_shell
{
	t_env		*env;
	t_cmdtable	*table;
	int			exitsts;
	int			unsetpwd;
	int			opwd;
}	t_shell;

t_shell 	g_shell;

#endif