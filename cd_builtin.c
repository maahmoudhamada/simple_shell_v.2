#include "shell.h"

char *set_paths(node_d *st)
{
  char *dir, *tmp;

  if (st->args[1] == NULL)
  {
    dir = _getenv("HOME", st);
    if(dir == NULL)
      return(NULL);
  }
  else if (_strcmp(st->args[1], "-") == 0)
  {
    tmp = _getenv("OLDPWD", st);
    dir = tmp ? _strdup(tmp) : _getenv("PWD", st);
    writer(dir, STDOUT_FILENO);
    writer("\n", STDOUT_FILENO);
    free(tmp);
  }

  else
  dir = _strdup(st->args[1]);

  return(dir);
}

int cd_builtin(node_d *st)
{
  char *dir, *OPWD, *CPWD;

  dir = set_paths(st);
  if(!dir)
    return(0);

  OPWD = getcwd(NULL, 0);
  if(chdir(dir) == -1)
  {
    error_handling(st, "can't cd to ");
    st->exitstat = 2;
  }
  CPWD = getcwd(NULL, 0);

  _setenv("OLDPWD", OPWD, st);
  _setenv("PWD", CPWD, st);
  free(OPWD), free(CPWD);
  free(dir);
  return(0);
}
