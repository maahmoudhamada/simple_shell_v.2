#include "shell.h"

/**
* gridup - Function duplicate grid (2d array)
*
* @grid: 2D array to be duplicated
* @sz: Size of grid
*
* Return: 2D array
*/

char **gridup(char **grid, int sz)
{
char **cpy;
int i = 0;

cpy = malloc((sz + 1) * sizeof(char *));

if (cpy == NULL)
return (NULL);

cpy[sz] = NULL;

for (i = 0; grid[i]; i++)
cpy[i] = _strdup(grid[i]);

return (cpy);
}

