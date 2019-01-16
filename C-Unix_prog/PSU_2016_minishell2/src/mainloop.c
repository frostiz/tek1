/*
1;4601;0c1;4601;0c1;4601;0c** mainloop.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:57:55 2017 Thibaut Trouvé
** Last update Mon May  1 12:17:06 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "main.h"
#include "my.h"
#include "gnl.h"

void	aff(char ***cmd)
{
  int   i;

  i = 0;
  while (cmd[i] != NULL)
    {
      print_tab(cmd[i]);
      i++;
    }
}

void	signo(int sign)
{
  (void)sign;
  my_putstr("\n$>");
}

int	mainloop(t_tab *data)
{
  int	ret;

  data->cmd = malloc(sizeof(t_cmd));
  if (data->cmd == NULL)
    return (-1);
  signal(SIGINT, signo);
  if (isatty(0) == 1)
    my_putstr("$>");
  data->input = get_next_line(0);
  while (data->input != NULL)
    {
      data->input = epure_input(data->input);
      data->cmd = get_commands(NULL, data->input);
      ret = check_cmd_error(data->cmd, &(data->exit_value));
      ret = exec_all_commands(&data, ret);
      free(data->input);
      if (isatty(0) == 1)
	my_putstr("$>");
      data->input = get_next_line(0);
    }
  return (0);
}
