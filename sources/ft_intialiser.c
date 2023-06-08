
#include "../include/minishell.h"

void	ft_intialize_shell(char **env)
{
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
	g_shell.unsetpwd = 0;
	g_shell.opwd = 0;
	g_shell.table = NULL;
}
