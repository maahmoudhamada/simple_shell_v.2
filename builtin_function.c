#include "shell.h"

int exit_builtin(node_d *st)
{
  if(st->args[1])
    custom_atoi(st);

  clean_memory(st);
  free_list(st->env_lst);
  free_list(st->pth_lst);
  free_list(st->alias_lst);
  exit(st->exitstat);
}

int env_builtin(node_d *st)
{
  lst *ptr;

  for (ptr = st->env_lst; ptr; ptr = ptr->next)
  {
    writer(ptr->data, STDOUT_FILENO);
    writer("\n", STDOUT_FILENO);
  }
  return(0);
}
