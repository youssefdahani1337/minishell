
#include <unistd.h>
#include <stdio.h>
 #include <fcntl.h>
 
int main(int ac, char **av)
{
	// if (ac < 0  || !av)
	// 	return (0);
	// int i = 0;
	// while (av[1][i])
	// {
	// 	printf("%c\n", av[1][i++]);
	// }
	int i = 0;
while (i< 100)
{
	int fo = fork();
	if (fo == 0)
	{
		printf("%i\n", i);
		break;
	}
	else
	{
		i++;
	}
}
	return (0);
}

