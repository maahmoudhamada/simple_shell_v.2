#include "shell.h"

void clean_memory(node_d *st)
{
  free(st->cmd);
  free(st->fline);
  free2d(st->args);
}
