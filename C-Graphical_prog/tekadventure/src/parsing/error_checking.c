/*
** error_checking.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dunret@epitech.eu>
** 
** Started on  Fri May 26 23:03:15 2017 Victor Dubret
** Last update Sun May 28 19:09:49 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

int		(*checking_graph[7])(t_map *) =
{check_background, check_walkzone, checking_walkzone, check_doorzone,
 checking_doorzone, check_objects, check_character};

static void		init_checking_message(char *message[7])
{
  message[0] = "No background in room number : %d\n";
  message[1] = "No walk zone in room number : %d\n";
  message[2] = "Invalid format walk zone in room number :%d\n";
  message[3] = "No walk zone in room number : %d\n";
  message[4] = "Invalid format walk zone in room number :%d\n";
  message[5] = "Invalid format objects in room number :%d\n";
  message[6] = "Invalid format character in room number :%d\n";
}

int		all_check(t_map *graph, int *check)
{
  int		i;
  char		*message[7];

  i = 0;
  init_checking_message(message);
  while (i < 7)
    {
      if (checking_graph[i](graph) == 1)
	{
	  *check = 1;
	  my_printf(message[i], graph->nb_room);
	  return (84);
	}
      i++;
    }
  return (0);
}

int		*error_checking(t_map *graph, int *ever_passed, int *check)
{
  int		i;

  i = 0;
  if (*check == 1)
    return (NULL);
  ever_passed = realloc_int(ever_passed);
  if (ever_passed == NULL)
    return (NULL);
  ever_passed[ever_passed[0]] = graph->nb_room;
  if (all_check(graph, check) == 84)
    return (NULL);
  while (graph->new_room != NULL && graph->new_room[i] != NULL)
    {
      if (is_ever_passed(graph->new_room[i]->nb_room, ever_passed) == 0)
	{
	  ever_passed = error_checking(graph->new_room[i], ever_passed, check);
	  if (ever_passed == NULL || *check == 1)
	    return (NULL);
	}
      i++;
    }
  return (ever_passed);
}
