/*
** check_cmd_invalid.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Mon May 15 15:28:00 2017 dubret_v
** Last update Sun May 21 17:05:23 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	is_only_space_(char *str)
{
  if (str[0] == '\0')
    return (1);
  return (0);
}

int		invalid_pipe(t_graph *graph)
{
  if (graph->left == NULL || graph->right == NULL ||
      is_only_space_(graph->left->command) == 1 ||
      is_only_space_(graph->right->command) == 1)
    {
      my_perror("Invalid null command.\n");
      return (1);
    }
  return (0);
}

int		invalid_and(t_graph *graph)
{
  if (graph->right == NULL ||
      is_only_space_(graph->right->command) == 1)
    {
      my_perror("Invalid null command.\n");
      return (1);
    }
  return (0);
}

int		invalid_redir(t_graph *graph)
{
  if (graph->left == NULL ||
      is_only_space_(graph->left->command) == 1)
    {
      my_perror("Invalid null command.\n");
      return (1);
    }
  else if (graph->right == NULL ||
	   is_only_space_(graph->right->command) == 1)
    {
      my_perror("Missing name for redirect.\n");
      return (1);
    }
  return (0);
}
