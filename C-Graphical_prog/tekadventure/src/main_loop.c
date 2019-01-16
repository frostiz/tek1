/*
** main_loop.c for main_loop.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Thu May 25 16:30:58 2017 Vincent Roye
** Last update Sun May 28 22:03:11 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>
#include	"tekadventure.h"
#include	"cinematic.h"
#include	"my.h"
#include	"dialog.h"

static void	init_first_scene(t_game *game, t_map *graph, t_loop *loop)
{
  loop->move_click = 0;
  loop->door = 0;
  loop->new_room = 0;
  loop->from.x = 637;
  loop->from.y = 647;
  loop->spawn.x = 637.0;
  loop->spawn.y = 647.0;
  loop->actual_pos.x = 637;
  loop->actual_pos.y = 647;
  loop->to.x = 100;
  loop->to.y = 100;
  init_zone(game, graph, loop->actual_pos);
  sfMouse_setPosition(loop->from, (sfWindow *)game->window);
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition(game->character->down_walk.sprite[0], loop->spawn);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[0], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

void		move_player(t_game *game, t_map *graph, t_loop *loop)
{
  game->background = graph->background;
  loop->to = sfMouse_getPosition((sfWindow *)game->window);
  if (check_valid_coord(graph->walkzone, int_to_float(loop->to)) != 1)
    {
      loop->from = move_character(game, loop->from, loop->to, graph->walkzone);
      loop->new_room = 0;
    }
  loop->actual_pos.x = (float)loop->from.x;
  loop->actual_pos.y = (float)loop->from.y;
  if (loop->from.x == -100 && loop->from.y == -100)
    sfRenderWindow_close(game->window);
  loop->move_click = 0;
  check_object(graph, loop->from, game);
}

t_map		*next_door(t_game *game, t_map *graph, t_loop *loop)
{
  loop->door = 0;
  while (graph->new_room[loop->door]->nb_room != loop->good_room)
    loop->door += 1;
  graph = graph->new_room[loop->door];
  loop->actual_pos.x = (float)loop->from.x;
  loop->actual_pos.y = (float)loop->from.y;
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfSprite_setPosition(game->character->down_walk.sprite[0],
		       loop->actual_pos);
  init_zone(game, graph, loop->actual_pos);
  loop->new_room = 1;
  return (graph);
}

void		house_parallax(t_game *game)
{
  sfVector2f	pos;

  if (my_strcmp(game->background, "pictures/map/house.jpg") == 0
      && game->same_bg == 1)
    {
      pos.x = 3.0;
      pos.y = 3.0;
      sfSprite_setScale(game->character->down_walk.sprite[0], pos);
    }
  else if (my_strcmp(game->background, "pictures/map/house.jpg") != 0)
    {
      pos.x = 1.0;
      pos.y = 1.0;
      sfSprite_setScale(game->character->down_walk.sprite[0], pos);
    }
}

int		main_loop(t_game *game, t_map *graph)
{
  t_loop	loop;

  init_first_scene(game, graph, &loop);
  if (print_first_text(game, &loop.from, graph) == 84)
    return (1);
  game->same_bg = 0;
  while (sfRenderWindow_isOpen(game->window) && game->end != 1)
    {
      game->background = graph->background;
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(game->window);
      if (sfEvtMouseButtonPressed)
	graph = check_move_click(game, graph, &loop);
      while (sfRenderWindow_pollEvent(game->window, &loop.event))
	loop = my_event(game, loop);
      if (game->inventory.is_open == 1)
	game->inventory.is_open = draw_inventory(game->window,
						 game->inventory,
						 game, loop.actual_pos);
      if (usual_event(game, graph, &loop) == 84)
	return (0);
    }
  return (0);
}
