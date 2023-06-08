#include "builtins.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	t_env *envlst;

	envlst = ft_env_fill(env);
	// ft_putstr_fd("\n\n\n", 1);
	// ft_env(envlst);
	ft_cd(argv , envlst);
	// ft_putstr_fd("\n\n\n", 1);
	// ft_env(envlst);
}