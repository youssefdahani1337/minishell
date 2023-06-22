
#include "../include/minishell.h"

void	ft_intialize_shell(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	remove_ctrl_c();
	signal(SIGINT, handler);
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
	g_shell.unsetpwd = 0;
	g_shell.opwd = 0;
	g_shell.env_save = env;
	g_shell.table = NULL;
}
