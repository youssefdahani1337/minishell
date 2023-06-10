#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
 #include <string.h>
int	main(void)
{
	//char	*line;

	//line = strdup("hello");
	if (fork() == 0)
	{
		system("leaks minishell");
		//scanf("%s", line);
		printf("hello");
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	system("leaks minishell");
}