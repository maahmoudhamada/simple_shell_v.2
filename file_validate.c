#include "shell.h"

/**
 * file_validate - Function to check executable file condition
 *
 * @pathname: Path of the executable file
 * @st: Structure to store cmd data
 *
 * Return: Zero (0) if file exists negative value other wise
 */

int file_validate(node_d *st)
{
  struct stat s;

  if (stat(st->cmd, &s) == 0)
  {
    if (access(st->cmd, X_OK) == 0)
    {
      return (0);
    }

    else
    {
      st->exitstat = 126;
      error_handling(st, "Permission denied");
    }
  }

  else
  {
    st->exitstat = 127;
    error_handling(st, "Permission denied");
  }

  return (-1);
}

