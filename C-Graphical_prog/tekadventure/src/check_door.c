/*
** check_door.c for check_door.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri May 26 15:36:30 2017 Vincent Roye
** Last update Sun May 28 21:40:16 2017 Vincent Roye
*/

#include        <SFML/Audio.h>
#include        <SFML/Graphics.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <fcntl.h>
#include        <math.h>
#include        <stdio.h>
#include        <string.h>
#include        "tekadventure.h"
#include	"my.h"

char		*next_spawn_coord(int room, t_map **next_room,
				 int actual_room, sfVector2i *pos)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  j = 1;
  while (next_room[i]->nb_room != room)
    i++;
  while (next_room[i]->doorzone[j][0] != actual_room)
    j++;
  pos->x = (next_room[i]->doorzone[j - 2][0] +
	    next_room[i]->doorzone[j - 1][0]) / 2;
  pos->y = (next_room[i]->doorzone[j - 2][1] +
	    next_room[i]->doorzone[j - 1][1]) / 2;
  str = my_strdup(next_room[i]->background);
  if (str == NULL)
    return (NULL);
  return (str);
}

static	int	init_values(t_map *graph, int *door)
{
  *door = next_len(graph->new_room);
  return (1);
}

int		check_gold(char *str, t_game *game,
			   sfVector2i tmp, sfVector2i *from)
{
  if (my_strcmp(str, "pictures/map/city5.png") == 0)
    if (game->inventory.gold_key == 0 || check_piece(game) < 5)
      {
	*from = init_vector(tmp.x, tmp.y);
	return (0);
      }
  return (1);
}

int		check_door(t_map *graph, sfVector2i *from,
			   int *good_room, t_game *game)
{
  int		i;
  int		door;
  char		*str;
  sfVector2i	tmp;

  i = init_values(graph, &door);
  tmp = init_vector(from->x, from->y);
  while (i <= door * 3)
    {
      if ((from->x > graph->doorzone[i][0] &&
	   from->x < graph->doorzone[i + 1][0]) &&
	  (from->y > graph->doorzone[i][1] &&
	   from->y < graph->doorzone[i + 1][1]))
	{
	  *good_room = graph->doorzone[i + 2][0];
	  str = next_spawn_coord(*good_room, graph->new_room,
				 graph->nb_room, from);
	  if (str == NULL)
	    return (-1);
	  return (check_gold(str, game, tmp, from) == 0 ? 0 : 1);
	}
      i += 3;
    }
  return (0);
}
