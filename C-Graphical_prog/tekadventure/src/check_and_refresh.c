/*
** check_and_refresh.c for check_and_refresh.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 15:30:38 2017 Vincent Roye
** Last update Sun May 28 22:43:20 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

void		refresh_game(t_game *game, t_map *graph, t_loop *loop)
{
  (void)graph;
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition(game->character->down_walk.sprite[0],
		       loop->actual_pos);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[0], NULL);
  sfRenderWindow_display(game->window);
}

t_map		*check_move_click(t_game *game, t_map *graph,
				  t_loop *loop)
{
  while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    loop->move_click = 1;
  if (loop->move_click == 1 &&
      (check_valid_coord(graph->walkzone,
			 loop->actual_pos) != 1))
    move_player(game, graph, loop);
  if (loop->new_room != 1 && check_door(graph, &loop->from,
					&loop->good_room, game) == 1)
    graph = next_door(game, graph, loop);
  return (graph);
}

int		usual_event(t_game *game, t_map *graph, t_loop *loop)
{
  int		room;

  room = 0;
  if (my_strcmp(game->background, "pictures/map/city5.png") == 0)
    {
      if (game->inventory.sword != 1)
	{
	  final_boss(game, graph);
	  return (84);
	}
      else
	{
	  final_boss_win(game, graph);
	  graph = search_the_room(graph, &room, NULL, graph);
	  end_game(game, graph);
	  return (84);
	}
    }
  house_parallax(game);
  refresh_game(game, graph, loop);
  return (0);
}
