/*
** check_object.c for check_object.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sun May 28 02:42:43 2017 Vincent Roye
** Last update Sun May 28 21:56:49 2017 Vincent Roye
*/

#include	<stdio.h>
#include	"tekadventure.h"
#include	"my.h"

void	check_inventory(char *inventory_pictures[8])
{
  inventory_pictures[0] = "pictures/ship/Gold_key.png";
  inventory_pictures[1] = "pictures/ship/Sword.png";
  inventory_pictures[2] = "pictures/ship/generator.png";
  inventory_pictures[3] = "pictures/ship/master.png";
  inventory_pictures[4] = "pictures/ship/turbine-1.png";
  inventory_pictures[5] = "pictures/ship/turbine-2.png";
  inventory_pictures[6] = "pictures/ship/wings-1.png";
  inventory_pictures[7] = "pictures/ship/wings-2.png";
}

static	void	what_is_object(t_map *graph, int i, t_game *game)
{
  char		*inventory_picture[8];
  int		j;

  j = 0;
  check_inventory(inventory_picture);
  while (j < 8)
    {
      if (my_strcmp(graph->objects.obj[i], inventory_picture[j]) == 0)
	{
	  if (j < 2)
	    {
	      if (j == 0)
		game->inventory.gold_key = 1;
	      else
		game->inventory.sword = 1;
	    }
	  else
	    game->inventory.piece_ship[j - 2] = 1;
	}
      j++;
    }
}

int		is_an_object(t_game *game, int i, t_map *graph, int max)
{
  game->stock_obj = my_realloc_tab(game->stock_obj);
  if (game->stock_obj == NULL)
    return (-1);
  game->stock_obj[max] = my_strdup(graph->objects.obj[i]);
  if (game->stock_obj[max] == NULL)
    return (-1);
  game->stock_obj[max + 1] = NULL;
  what_is_object(graph, i, game);
  return (1);
}

int		check_object(t_map *graph,
			     sfVector2i from, t_game *game)
{
  int		i;
  int		max;

  max = arr_len(game->stock_obj);
  i = 0;
  if (game->nb_obj == 0)
    return (0);
  while (i < game->nb_obj * 2)
    {
      if ((from.x > graph->objects.object[i + 1][0] &&
	   from.x < graph->objects.object[i + 2][0]) &&
	  (from.y > graph->objects.object[i + 1][1] &&
	   from.y < graph->objects.object[i + 2][1]))
	{
	  if (is_an_object(game, i, graph, max) == -1)
	    return (-1);
	  return (1);
	}
      i += 2;
    }
  return (0);
}
