
#include "../include/minishell.h"

void		ft_intialize_shell(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
	g_shell.unsetpwd = 0;
	g_shell.table = NULL;
}
