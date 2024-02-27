#include "shell.h"

void multi_execution(node_d *st)
{
  char **lines, *linecp;
  int i = 0;
  
  linecp = _strdup(st->fline);
  
  lines = tokenizer(linecp, ";");

  free(st->fline);
  for (i = 0; lines[i]; i++)
  {
    st->fline = _strdup(lines[i]);
    data_handler(st);
    execution(st);
    clean_memory(st);
  }
  free2d(lines);
  free(linecp);
}
