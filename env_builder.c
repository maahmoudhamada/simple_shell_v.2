#include "shell.h"

void env_builder(node_d *st)
{
  lst *head = NULL;
  int i = 0;
  
  for (i = 0; environ[i]; i++)
    node_add(&head, environ[i]);
  
  st->env_lst = head;
}

