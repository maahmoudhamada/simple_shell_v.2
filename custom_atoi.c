#include "shell.h"

int _isdigit(int c)
{
  if (c >= 0 && c <= 9)
    return(1);

  else
    return(0);
}


int str_validation(char *str)
{
  int i = 0;

  for (i = 0; str[i]; i++)
  {
    if(!_isdigit(str[i] - '0'))
      return(0);
  }
  return(1);
}

void custom_atoi(node_d *st)
{
  int digit, n, i;
  char *str = st->args[1];
  digit = n = i = 0;

  if (str[0] == '-' || !str_validation(str))
  {
    st->exitstat = 2;
    error_handling(st, "Illegal number: ");
    return;
  }

  for (i = 0; str[i]; i++)
  {
    digit = str[i] - '0';
    n = (n * 10) + digit;
  }

  if (n >= 256)
    st->exitstat = n % 256;
  
  st->exitstat = n;
}
