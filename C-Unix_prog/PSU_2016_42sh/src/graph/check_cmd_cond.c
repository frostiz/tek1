/*
** check_cmd_cond.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Mon May 15 15:23:05 2017 dubret_v
** Last update Mon May 15 15:23:40 2017 dubret_v
*/

#include "mysh.h"

int	is_pipe(t_graph *graph)
{
  if (graph->limit == 1 || graph->limit == 3)
    return (0);
  return (1);
}

int	is_and(t_graph *graph)
{
  if (graph->limit == 2)
    return (0);
  return (1);
}

int	is_redir(t_graph *graph)
{
  if (graph->limit >= 4 && graph->limit < 8)
    return (0);
  return (1);
}
