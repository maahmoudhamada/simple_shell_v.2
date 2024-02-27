#include "shell.h"
#include <string.h>

/**
* wordCount - Function to count number of words
*
* @s: String contains words
*
* Return: Number of words
*/

int wordCount(char *s, char *deli)
{
  char *temp, *token;
  int wrdcnt = 0;

  if (s == NULL)
    return (0);
  temp = strdup(s);
  token = strtok(temp, deli);

  while (token)
  {
    wrdcnt++;
    token = strtok(NULL, deli);
  }

  free(temp);
  return (wrdcnt);
}

/**
* tokenizer - Function to split string into 2d array
*
* @s: String to parase to 2d array
* @deli: delimeter between words
*
* Return: grid (2d array)
*/
char **tokenizer(char *s, char *deli)
{
  char **grid, *token, *temp;
  int wrdcnt = 0, i = 0;

  if (s == NULL)
    return (NULL);

  temp = strdup(s);
  wrdcnt = wordCount(s, deli);

  grid = malloc((wrdcnt + 1) * sizeof(char *));
  if (grid == NULL)
    return (NULL);

  token = strtok(temp, deli);

  for (i = 0; i < wrdcnt; i++)
  {
    grid[i] = strdup(token);
    if (grid[i] == NULL)
    {
      free2d(grid);
      return (NULL);
    }
    token = strtok(NULL, deli);
  }

  grid[wrdcnt] = NULL;

  free(temp);
  return (grid);
}

