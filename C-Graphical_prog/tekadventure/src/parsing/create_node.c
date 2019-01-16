/*
** create_node.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Thu May 25 15:50:36 2017 dubret_v
** Last update Sat May 27 20:23:37 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

t_map		*create_node(t_map *map, int *room, char *str)
{
  t_map		*new_node;

  new_node = malloc(sizeof(t_map));
  if (new_node == NULL)
    return (NULL);
  *room = my_getnbr(str);
  new_node->nb_room = *room;
  new_node->name_room = NULL;
  new_node->background = NULL;
  new_node->walkzone = NULL;
  new_node->doorzone = NULL;
  new_node->objects.object = NULL;
  new_node->objects.obj = NULL;
  new_node->objects.nb_passed = 0;
  new_node->characters.character = NULL;
  new_node->characters.charac = NULL;
  new_node->characters.sentence = NULL;
  new_node->characters.nb_passed = 0;
  new_node->new_room = NULL;
  if (map == NULL)
    return (new_node);
  else
    return (map);
}
