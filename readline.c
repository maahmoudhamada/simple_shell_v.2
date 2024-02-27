#include "shell.h"

void null_switching(char **line)
{
  free(*line);
  *line = NULL;
}

void readline(node_d *st, int mode)
{
  size_t n = 0;
  ssize_t gt = 0;

  gt = getline(&st->fline, &n, stdin);

  if(gt == -1)
  {
    free(st->fline);
    free_list(st->env_lst);
    free_list(st->pth_lst);
    free_list(st->alias_lst);
    if(mode)
      writer("\n", 0);
    exit(st->exitstat);
  }

  else if (st->fline[0] == '\n' && st->fline[1] == '\0')
  {
    null_switching(&st->fline);
    return;
  }

  else if(st->fline[gt - 1] == '\n')
  {
    st->fline[gt - 1] = '\0';
    gt--;
  }

  if(cmd_formating(st, gt) == -1)
    null_switching(&st->fline);
  
}
