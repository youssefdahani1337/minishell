#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "debug.h"
#define BUFFER_SIZE 1024

void read_file(int fd)
{ 
    char    c;

    while (read(fd, &c, 1))
    {
        write (1,&c, 1);
    }
}
