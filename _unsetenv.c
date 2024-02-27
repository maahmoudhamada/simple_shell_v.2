#include "shell.h"

void free_node(lst *del)
{
  free(del->data);
  free(del);
}

int _unsetenv(const char *name, node_d *st)
{
  char *tmp, *token, *name_cp;
  lst *pre, *del;

  if(name == NULL || _strlen(name) == 0 || !check_name(name))
    return(-1);
  name_cp = _strdup(name);

  tmp = _strdup(st->env_lst->data);
  token = strtok(tmp, "=");
  if(_strcmp(token, name) == 0)
  {
    del = st->env_lst;
    st->env_lst = st->env_lst->next;
    free_node(del);
  }

  else
{
    free(tmp);
    for (pre = st->env_lst; pre; pre = pre->next)
    {
      tmp = _strdup(pre->next->data);
      token = strtok(tmp, "=");
      if(_strcmp(token, name) == 0)
      {
        del = pre->next;
        break;
      }
      free(tmp);
    }
    pre->next = del->next;
    free_node(del);
  }

  free(tmp);
  free(name_cp);
  return(0);
}


int pre_unsetenv(node_d *st)
{
  char **env_cpy, *token, *name;
  int flag = 0, i = 0;

  if(_strlen2d(st->args) != 2)
  {
    writer("too few arugments to unsetenv\n", STDERR_FILENO);
    return(0);
  }

  name = st->args[1];
  env_cpy = convert_list(st->env_lst);
  for (i = 0; env_cpy[i]; i++)
  {
    token = strtok(env_cpy[i], "=");
    if(_strcmp(name, token) == 0)
      flag = 1;
  }

  if(flag)
  {
    if(_unsetenv(name, st) == -1)
      writer("Invalid variable name\n", STDERR_FILENO);
  }
  free2d(env_cpy);
  return(0);
}
