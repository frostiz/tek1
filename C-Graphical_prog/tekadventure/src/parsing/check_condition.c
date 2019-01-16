/*
** check_condition.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 00:53:30 2017 Victor Dubret
** Last update Sun May 28 19:09:00 2017 Victor Dubret
*/

#include "tekadventure.h"

int	check_objects(t_map *graph)
{
  int	len;

  if (graph->objects.obj == NULL && graph->objects.object == NULL)
    return (0);
  if (graph->objects.obj == NULL)
    return (1);
  len = arr_len(graph->objects.obj);
  if ((graph->objects.object[0][0] % 2 != 0) ||
      (len != (graph->objects.object[0][0] / 2)))
    return (1);
  return (0);
}

int	check_character(t_map *graph)
{
  int	len;
  int	size;

  if (graph->characters.charac == NULL && graph->characters.character == NULL
      && graph->characters.sentence == NULL)
    return (0);
  len = arr_len(graph->characters.charac);
  size = arr_len(graph->characters.sentence);
  if (len != size)
    return (1);
  else if (graph->characters.character[0][0] % 2 != 0 ||
	   (len != graph->characters.character[0][0] / 2))
    return (1);
  return (0);
}
