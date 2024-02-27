#include "shell.h"

int builtin_check(node_d *st, char *cmd)
{
  int (*f)(node_d *st);

  if(cmd == NULL)
    return(-1);

  f = built_selector(cmd);
  if(f == NULL)
    return(-1);

  if(f(st) == 0)
    return(0);

  else
    return(-1);
}


int (*built_selector(char *cmd))(node_d *st)
{
  bstruc built_arr[] = {
    {"exit", exit_builtin},
    {"env", env_builtin},
    {"setenv", pre_setenv},
    {"unsetenv", pre_unsetenv},
    {"cd", cd_builtin},
    {"alias", alias_builtin},
    {NULL, NULL}};
  int i = 0;

  for (i = 0; built_arr[i].bcmd; i++)
  {
    if(_strcmp(built_arr[i].bcmd, cmd) == 0)
      return(built_arr[i].bfunc);
  }
  return(NULL);
}
