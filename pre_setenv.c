#include "shell.h"

int check_name(const char *name)
{
  int i = 0;

  for (i = 0; name[i]; i++)
    if(name[i] == '=')
      return(0);
  return (1);
}

int _setenv(const char *name, const char *value, node_d *st)
{
  char *name_cp, *value_cp, *token, *tmp, *out;
  int i = 0, len = 0;
  lst *ptr;

  if(name == NULL || _strlen(name) == 0 || !check_name(name))
    return(-1);
  
  len = list_len(st->env_lst);
  name_cp = _strdup(name), value_cp = _strdup(value);

  for (i = 0, ptr = st->env_lst; ptr; i++, ptr = ptr->next)
  {
    tmp = _strdup(ptr->data);
    token = strtok(tmp, "=");
    if(_strcmp(token, name_cp) == 0)
      break;
    free(tmp);
  }
  out = _strconcat(name_cp, value_cp, 1);
  if(i < len)
  {
    free(ptr->data);
    ptr->data = _strdup(out);
    free(tmp);
  }
  else
    node_add(&st->env_lst, out);

  free(name_cp), free(value_cp), free(out);
  return(0);
}

int pre_setenv(node_d *st)
{
  char *name, *value;

  if(_strlen2d(st->args) != 3)
  {
    writer("too few arugments to setenv\n", STDERR_FILENO);
    return(0);
  }
  name = st->args[1];
  value = st->args[2];

 if (_setenv(name, value, st) == -1) 
    writer("Invalid variable name\n", STDERR_FILENO);



  return(0);
}

