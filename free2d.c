#include "shell.h"

/**
* free2d - Function to free 2d array
*
* @grid: 2D array
*
* Return: Void
*/

void free2d(char **grid)
{
int i = 0;
for (i = 0; grid[i]; i++)
free(grid[i]);
free(grid);
}

