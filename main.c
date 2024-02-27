#include "shell.h"

/**
* prompt_printer - Function to print shell prompt
*
* Return - void
*/

void multi_execution(node_d *st);

void prompt_printer(void)
{
  writer(PROMPT, STDIN_FILENO);
  fflush(stdout);
}

/**
* signal_handler - Function to handler SIGINT signal (ctrl + c)
*
* @signum: Signal number
*
* Return: Void
*/

void signal_handler(int signum __attribute__((unused)))
{
  signal(SIGINT, signal_handler);
  writer("\n", STDIN_FILENO);
  prompt_printer();
}

/**
* main - Entry point to start shell
*
* @argc: Number of arguments
* @argv: Arguments enterd
*
* Return: Zero (0) on success non-zero otherwise
*/

int main(int argc __attribute__((unused)), char **argv)
{
  int interactive = isatty(STDIN_FILENO);
  node_d data;

  signal(SIGINT, signal_handler);

  env_builder(&data);

  data.filen = argv[0], data.cmdno = 0, data.exitstat = 0;
  data.alias_lst = NULL, data.fline = NULL, data.pth_lst = NULL;

  while(1)
  {
    data.flag = 0;
    if (interactive)
      prompt_printer(); 
    readline(&data, interactive);

    if(data.fline == NULL)
      continue;
    data.cmdno++; 
    if(!data.flag)
    {
      if (data_handler(&data) == -1)
      {
        clean_memory(&data);
        continue;
      }
      execution(&data);
      clean_memory(&data);
    }

    else
      multi_execution(&data);
  }

  return(data.exitstat);
}
