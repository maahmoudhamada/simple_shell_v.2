#include "shell.h"

int value_surr(char **str)
{
  char *tmp, *strcpy;
  int x = 0, y = 0, len = 0;

  len = _strlen(*str);

  if (*(*str + 0) == 39 && *(*str + len - 1) == 39)
    return (1);

  tmp = malloc((len + 3) * sizeof(char));
  if (tmp == NULL)
    return ('\0');

  tmp[0] = 39, tmp[len + 1] = 39;

  strcpy = _strdup(*str);

  for (x = 0, y = 1; strcpy[x]; x++, y++)
    tmp[y] = strcpy[x];
  tmp[++y] = '\0';

  free(*str);
  *str = tmp;

  free(strcpy);
  return (0);
}

char **alias_formating(char *line)
{
  char **grid, *tmp;
  int i = 0;

  tmp = _strdup(line + _strlen("alias "));

  for (i = 0; tmp[i]; i++)
  {
    if (tmp[i] == ' ' && tmp[i + 1] == '-')
      continue;
    if (tmp[i] == ' ')
      tmp[i] = '\n';
  }
  grid = tokenizer(tmp, "\n");

  free(tmp);
  return (grid);
}

int name_chk(node_d *st, char *name)
{
  char *token, *tmp;
  lst *ptr;

  for (ptr = st->alias_lst; ptr; ptr = ptr->next)
  {
    tmp = _strdup(ptr->data);
    token = strtok(tmp, "=");
    if (_strcmp(token, name) == 0)
    {
      free(tmp);
      return (1);
    }

    free(tmp);
  }

  return (0);
}

int alias_builtin(node_d *st)
{
  char **grid, *name, *value;
  int i = 0, chk = 0;

  if(_strlen2d(st->args) == 1)
  {
    print_list(st->alias_lst, NULL);
    return(0);
  }

  grid = alias_formating(st->fline);

  for (i = 0; grid[i]; i++)
  {
    name = strtok(grid[i], "=");
    value = strtok(NULL, "=");

    chk = name_chk(st, name);

    if (name && chk && !value)
      print_list(st->alias_lst, name);

    else if (name && !value && !chk)
    {
      writer("alias: ", STDOUT_FILENO);
      writer(name, STDOUT_FILENO);
      writer(" not found\n", STDOUT_FILENO);
      st->exitstat = 1;
    }

    else
      alias_builder(st, name, value);
  }

  free2d(grid);
  return (0);
}
