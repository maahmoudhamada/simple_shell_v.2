#include "shell.h"

void print_list(lst *h, char *name)
{
  lst *ptr;
  char *token, *tmp;

  if(name)
  {
    for (ptr = h; ptr; ptr = ptr->next)
    {
      tmp = _strdup(ptr->data);
      token = strtok(tmp, "=");
      if(_strcmp(token, name) == 0)
        printf("%s\n", ptr->data);
      free(tmp);
    }
  } 
  else
  {
    for (ptr = h; ptr; ptr = ptr->next)
      printf("%s\n", ptr->data);
  }
}
