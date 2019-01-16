/*
** display_graph.c for Lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Fri Apr 21 19:13:10 2017 dubret_v
** Last update Sun Apr 30 16:15:45 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void	fill_that(char **ever_passed, char *name, char *s2)
{
  int		i;

  i = 0;
  while (ever_passed[i] != NULL)
    i++;
  ever_passed[i] = my_strdup(name);
  if (s2 != NULL)
    ever_passed[i] = my_strdup(s2);
}

int		display_graph(t_map *graph, char **ever_passed)
{
  t_map		*tmp;
  int		i;

  i = 0;
  tmp = graph;
  fill_that(ever_passed, graph->data.name, NULL);
  print_tab(ever_passed);
  my_printf("-----------------------------\n");
  my_printf("name %s\n", graph->data.name);
  my_printf("data.x %d\n", graph->data.x);
  my_printf("data.y %d\n", graph->data.y);
  my_printf("data.status %d\n", graph->data.pos);
  print_tab(tmp->link.link_name);
  while (tmp->link.link_address[i] != NULL)
    {
      if (tmp->link.link_address != NULL &&
	  is_passed(ever_passed, tmp->link.link_name[i]) == 0)
	display_graph(tmp->link.link_address[i], ever_passed);
      i++;
    }
  return (0);
}
