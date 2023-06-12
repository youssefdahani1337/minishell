#include <stdio.h>
#include <errno.h>
#include <sys/param.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
 #include <string.h>
int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char *str[] = {"ls", "-l", NULL};
	execve("/bin/ls", str, env);
}