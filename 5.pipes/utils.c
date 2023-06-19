
#include "../include/multipipes.h"

int	ft_access_check(char *cmd)
{
	if (!access(cmd, F_OK))
	{
		if (!access(cmd, X_OK))
			return (1);
		return (2);
	}
	return (0);
}