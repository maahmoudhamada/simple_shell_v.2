#include "shell.h"

int path_fetching(node_d *st, char *cmd);
int data_handler(node_d *st)
{
  char **grid;
  char *tmp = _strdup(st->fline);
  grid = tokenizer(tmp, " ");
/*   printf("grid[0] == [%s]\n", grid[0]);  */
  st->args = gridup(grid, _strlen2d(grid));
  var_replacement(st); 
  st->cmd = _strdup(st->args[0]);
  free2d(grid), free(tmp);

  if (builtin_check(st, st->cmd) == 0)
    return(-1);
   
  alias_extraction(st);

  if(path_fetching(st, st->cmd) == 2)
    return(-1);
  if (file_validate(st) == -1)
    return(-1);

  return(0);
}
