#include "shell.h"

/**
* writer - Function to print character & integer
*
* @buf: Buffer
* @fd: Stream no
*
* Return: Number of character printed
*/

int writer(char *buf, int fd)
{
int sz;

if (buf == NULL)
return (0);

sz = _strlen(buf);

write(fd, buf, sz);
return (sz);
}

