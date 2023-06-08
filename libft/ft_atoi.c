
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		sign;
	long	result;

	j = 0;
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = -1 * (str[i ++] - 44);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (j == 19 || result > 922337203685477580))
			return (-1);
		else if (result == 922337203685477580)
		{
			if ((sign == 1 && str[i] > 7) || (sign == -1 && str[i] > 8))
				return (-1);
		}
		result = (result * 10) + (str[i ++] - 48);
		j++;
	}
	return ((result * sign) % 256);
}
