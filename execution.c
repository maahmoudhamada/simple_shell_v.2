#include "shell.h"

/**
* execution - Function to execute the shell command
*
* @st: Structure to store cmd data
* @line: Line recieved from user to free it on error
*
* Return: Void
*/

void execution(node_d *st)
{
  pid_t child_id;
  char **env;

  env = convert_list(st->env_lst);
  child_id = fork();
  
  if (child_id == -1)
    perror("fork: ");

  else if (child_id == 0)
    execve(st->cmd, st->args, env);

  else
  {
    int wstatus;
    wait(&wstatus);
    if (WIFEXITED(wstatus))
      st->exitstat = WEXITSTATUS(wstatus);
    free2d(env);
  }
}

