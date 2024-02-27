#include "shell.h"

void remove_surr(char **line)
{
  char *new, *tmp;
  int i = 0, j = 0, len = 0;
  
  tmp = _strdup(*line);
  len = _strlen(tmp);

  new = malloc((len - 1) * sizeof(char));

  if(new == NULL)
    return;

  for (j = 0, i = 1; i < (len - 1); i++, j++)
    new[j] = tmp[i];

  new[j] = '\0';

  free(tmp);
  *line = new;
}


void alias_extraction(node_d *st)
{
  char **grid, *token, *line;
  int i = 0, f = 0;

  if (st->alias_lst == NULL)
    return;
  
  grid = convert_list(st->alias_lst);

  for (i = 0; grid[i]; i++)
  {
    token = strtok(grid[i], "=");
    if(_strcmp(st->cmd, token) == 0)
    {
      line = strtok(NULL, "=");
      f = 1;
    }
  }
  if(!f)
  {
    free2d(grid);
    return;
  }
  remove_surr(&line);
  
  free2d(st->args), free(st->cmd), free2d(grid);
  grid = tokenizer(line, " ");

  st->args = gridup(grid, _strlen2d(grid));
  st->cmd = _strdup(st->args[0]);

  free2d(grid), free(line);
}
