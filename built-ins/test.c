
#include <unistd.h>
#include <stdio.h>
#include <sys/param.h>
#include <stdlib.h>

int	main(void)
{
	char	buf[MAXPATHLEN];

	if (!getcwd(buf, MAXPATHLEN))
		printf("not good\n");
	else
		printf("Success %s\n", buf);
	return (0);
}