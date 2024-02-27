#include "shell.h"

char *value_changer(node_d *st, char *value)
{
  char **grid, *token, *tmp;
  int i = 0, f = 0;

  grid = convert_list(st->alias_lst);

  if(grid == NULL)
    return(NULL);

  for (i = 0; grid[i]; i++)
  {
    token = strtok(grid[i], "=");
    if(_strcmp(value, token) == 0)
    {
      tmp = _strdup(strtok(NULL, "="));
      f = 1;
    }
  }

  if(!f)
    tmp = _strdup(value);

  free2d(grid);
  return(tmp);
}

void alias_builder(node_d *st, char *name, char *value)
{
  char *namecpy, *valuecpy, *tmp;
  char *out, *token;
  lst *ptr;
  int f = 0;

  namecpy = _strdup(name);
  valuecpy = value_changer(st, value);
  

  value_surr(&valuecpy);
  out = _strconcat(namecpy, valuecpy, 1);

  for (ptr = st->alias_lst; ptr; ptr = ptr->next)
  {
    tmp = _strdup(ptr->data);
    token = strtok(tmp, "=");
    if(_strcmp(token, namecpy) == 0)
    {
      free(ptr->data);
      ptr->data = _strdup(out);
      f = 1;
      free(tmp);
      break;
    }
    free(tmp);
  } 
  
  if(!f)
    node_add(&st->alias_lst, out);

  free(namecpy), free(valuecpy), free(out);
}

