#include "shell.h"

int list_len(lst *head)
{
  lst *ptr;
  int len = 0;

  for (ptr = head; ptr; ptr = ptr->next)
    len++;

  return(len);
}



char **convert_list(lst *head)
{
  int len = 0, i = 0, j = 0;
  char **env;
  lst *ptr;

  len = list_len(head);
  
  env = malloc((len + 1) * sizeof(char *));
  if(env == NULL)
    return(NULL);

  env[len] = NULL;

  for (ptr = head, i = 0; i < len; i++, ptr = ptr->next)
  {
    env[i] = malloc((_strlen(ptr->data) + 1) * sizeof(char));
    if(env[i] == NULL)
    {
      free2d(env);
      return(NULL);
    }
    for (j = 0; ptr->data[j]; j++)
      env[i][j] = ptr->data[j];
    env[i][j] = '\0';
  }

  return(env);
}
