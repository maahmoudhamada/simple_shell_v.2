#include "shell.h"

void var_repl(node_d *st, int pos)
{
  char *varval, *str;

  str = _strdup(st->args[pos]);
  free(st->args[pos]);

  if (str[1] == '$')
    varval = linenum_convert(getpid());
    

  else if (str[1] == '?')
  {
    if(st->exitstat == 0)
      varval = _strdup("0");
    else
      varval = linenum_convert(st->exitstat);
  }

  else
  {
    varval = _getenv(str + 1, st);
    if(varval == NULL)
    {
      st->args[pos] = _strdup(EMPTYSTR);
      free(str);
      return;
    }
  }
  
  st->args[pos] = _strdup(varval);
  free(varval), free(str); 
}

void var_replacement(node_d *st)
{
  int i = 0;

  for (i = 0; st->args[i]; i++)
  {
    if(st->args[i][0] == '$' && st->args[i][1])
      var_repl(st, i);
  }
}



