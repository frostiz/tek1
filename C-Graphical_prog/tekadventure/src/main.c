/*
** main.c for main.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Fri May  5 01:51:09 2017 Vincent Roye
** Last update Thu Jun  1 10:32:32 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<math.h>
#include	<stdio.h>
#include	"tekadventure.h"
#include	"main_screen.h"
#include	"character.h"

int		init_first_zone(t_game *game, t_map *graph)
{
  sfVector2f	player_coord;

  player_coord.x = 637.0;
  player_coord.y = 647.0;
  game->save = init_vector(637, 647);
  game->bg->sprite = sfSprite_create();
  game->bg->texture = sfTexture_createFromFile(graph->background, NULL);
  if (game->bg->texture == NULL)
    return (-1);
  sfSprite_setTexture(game->bg->sprite, game->bg->texture, sfTrue);
  sfSprite_move(game->character->up_walk.sprite[0], player_coord);
  return (0);
}

static	t_game	*init_game()
{
  t_game	*game;
  int		check;

  check = 0;
  game = malloc(sizeof(t_game));
  if (game == NULL)
    return (NULL);
  game->inventory = init_inventory(&check);
  if (check == 1)
    return (NULL);
  game->character = malloc(sizeof(t_character));
  if (game->character == NULL)
    return (NULL);
  game->bg = malloc(sizeof(t_background));
  if (game->bg == NULL)
    return (NULL);
  game->window = create_window("TekAdventure", WIDTH, HEIGHT);
  if (!(game->window))
    return (NULL);
  game->stock_obj = malloc(sizeof(char *));
  if (game->stock_obj == NULL)
    return (NULL);
  game->stock_obj[0] = NULL;
  return (game);
}

int		my_tekadventure(char *str)
{
  t_map		*graph;
  t_game	*game;

  graph = create_graph(str);
  if (graph == NULL)
    return (84);
  game = init_game();
  if (game == NULL)
    return (84);
  if (init_character(game->character) == 1)
    return (84);
  sfRenderWindow_setFramerateLimit (game->window, 100);
  if (init_first_zone(game, graph) == -1)
    return (84);
  game->music = sfMusic_createFromFile("sounds/lost_wood.ogg");
  if (!game->music)
    return (84);
  sfMusic_setLoop(game->music, sfTrue);
  sfMusic_play(game->music);
  game->end = 0;
  main_loop(game, graph);
  sfMusic_destroy(game->music);
  sfRenderWindow_destroy(game->window);
  return (0);
}

int			main(int ac, char **av, char **env)
{
  (void)ac;
  if (check_env(env) == -1)
    return (84);
  if (main_screen_loop() == 84)
    return (84);
  if (launch_cinematic() == 84)
    return (84);
  if (my_tekadventure(av[1]) == 84)
    return (84);
  return (0);
}
