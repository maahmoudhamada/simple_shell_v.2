#include "shell.h"

/**
* error_handling - Function to print error message
*
* @st: Structure contains cmd data
*
* Return: Void
*/

void error_handling(node_d *st, char *erro_mssg)
{
char *tmp, *deli = ": ";

tmp = linenum_convert(st->cmdno);

writer(st->filen, STDERR_FILENO);
writer(deli, STDERR_FILENO);
writer(tmp, STDERR_FILENO);
writer(deli, STDERR_FILENO);
writer(st->cmd, STDERR_FILENO);
writer(deli, STDERR_FILENO);
writer(erro_mssg, STDERR_FILENO);
if(_strcmp(st->cmd, "exit") == 0)
  writer(st->args[1], STDERR_FILENO);
  else if(_strcmp(st->cmd, "cd") == 0)
    writer(st->args[1], STDERR_FILENO);
writer("\n", STDERR_FILENO);

free(tmp);
}

