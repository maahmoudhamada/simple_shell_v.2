#include "shell.h"

char *_getenv(const char *name, node_d *st)
{
  char **env, *token, *path_value = NULL;
  int i = 0;

  env = convert_list(st->env_lst);

  for (i = 0; env[i]; i++)
  {
    token = strtok(env[i], "=");
    if(_strcmp(token, name) == 0)
    {
      path_value = _strdup(strtok(NULL, "="));
      break;
    }
  }

  free2d(env);
  return(path_value);
}

int starting(char *cmd)
{
  if(cmd[0] == 47)
    return(1);
  else
    return(0);
}

int path_builder(node_d *st)
{
  char **pathgrid, *pathval;
  int flag = 0, i = 0;

  pathval = _getenv("PATH", st);

  if(pathval == NULL)
  {
    flag = starting(st->cmd);
    if(flag == 1)
      return(1);
    else
      return(2);
  }

  pathgrid = tokenizer(pathval, ":");

  for (i = 0; pathgrid[i]; i++)
    node_add(&st->pth_lst, pathgrid[i]);

  free(pathval), free2d(pathgrid);
  return(0);
}


int path_fetching(node_d *st, char *cmd)
{
  int flag = 0, i = 0;
  char **tmp, *out;
  struct stat s;

  if(path_builder(st) == 2)
  {
    st->exitstat = 127;
    error_handling(st, "not found");
    return(2);
  }

  tmp = convert_list(st->pth_lst);
  for (i = 0; tmp[i]; i++)
  {
    out = _strconcat(tmp[i], cmd, 0);
    if(access(out, X_OK) == 0 && stat(out, &s) == 0)
    {
      flag = 1;
      break;
    }
    free(out);
  }
  free2d(tmp);
  if(!flag)
    return(-1);

  free(st->cmd);
  st->cmd = _strdup(out);
  free(out);
  return(0);
}

