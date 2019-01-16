/*
** init_ever_passed.c for lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun Apr 30 17:47:45 2017 dubret_v
** Last update Sun Apr 30 17:48:28 2017 dubret_v
*/

#include		<stdlib.h>
#include		"lemin.h"

t_ever_passed		*init_ever_passed(t_ever_passed *ever_passed,
					  t_map *graph, t_name_path path)
{
  if (path.name == NULL)
    {
      ever_passed = init_passed(ever_passed, graph->link.link_name,
				graph->data.name, graph->data.name);
      if (ever_passed == NULL)
	return (NULL);
    }
  else
    {
      ever_passed = init_passed(ever_passed, graph->link.link_name,
				graph->data.name, path.name);
      if (ever_passed == NULL)
	return (NULL);
    }
  return (ever_passed);
}
