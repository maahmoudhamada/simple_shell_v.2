#include "shell.h"

void chk_spec(node_d *st)
{
  int i = 0; 

  for (i = 0; st->fline[i]; i++)
  {
    if(st->fline[i] == ';')
      st->flag = 1;
  }    
}

int _isspace(char c)
{
  int spaces[] = {9, 32}, i = 0;

  for (i = 0; i < 2; i++)
    if (spaces[i] == c)
      return (1);

  return (0);
}


int cmd_formating(node_d *st, ssize_t gt)
{
  int i = 0, count = 0, j = 0;
  char buf[1024];

  for (i = 0; st->fline[i]; i++)
    if(_isspace(st->fline[i]))
      count++;

  if ((int) gt == count)
    return(-1);
  
  for (i = 0; st->fline[i]; i++)
  {
    if(_isspace(st->fline[i]))
      continue;

    else if (_isspace(st->fline[i]) == 0 && _isspace(st->fline[i + 1]) == 1)
    {
      buf[j++] = st->fline[i];
      buf[j++] = ' ';
      continue;
    }

    else
      buf[j++] = st->fline[i];
  }

  buf[j] = '\0';
  free(st->fline);
  st->fline = _strdup(buf);
  chk_spec(st);
  return(0);
}
