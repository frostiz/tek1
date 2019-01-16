/*
** init_zone.c for init_zone.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 12:09:47 2017 Vincent Roye
** Last update Sun May 28 12:57:33 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>
#include	"tekadventure.h"
#include	"cinematic.h"
#include	"my.h"
#include	"dialog.h"

static int	init_values(t_game *game, t_map *graph,
			    sfVector2f player_coord, int *i)
{
  *i = 0;
  game->bg->sprite = sfSprite_create();
  game->bg->texture = sfTexture_createFromFile(graph->background, NULL);
  if (game->bg->texture == NULL)
    return (-1);
  sfSprite_setTexture(game->bg->sprite, game->bg->texture, sfTrue);
  sfSprite_setPosition(game->character->up_walk.sprite[0], player_coord);
  game->same_bg = 1;
  game->nb_obj = arr_len(graph->objects.obj);
  game->nb_char = arr_len(graph->characters.charac);
  if (game->nb_obj == 0)
    return (0);
  game->obj = malloc(sizeof(t_objects *) * (game->nb_obj + 1));
  if (game->obj == NULL)
    return (-1);
  return (2);
}

static int	check_obj(t_game *game, t_map *graph,
			  int *i)
{
  while (*i < game->nb_obj)
    {
      game->obj[*i] = malloc(sizeof(t_objects));
      if (game->obj[*i] == NULL)
	return (-1);
      game->obj[*i]->sprite = sfSprite_create();
      game->obj[*i]->texture =
	sfTexture_createFromFile(graph->objects.obj[*i], NULL);
      game->obj[*i]->name = graph->objects.obj[*i];
      if (!(game->obj[*i]->texture))
	return (-1);
      sfSprite_setTexture(game->obj[*i]->sprite,
			  game->obj[*i]->texture, sfTrue);
      sfSprite_setPosition(game->obj[*i]->sprite,
			   get_pos_object(graph->objects.object,
					  *i + 1));
      (*i)++;
    }
  return (0);
}

int		check_char(t_game *game, t_map *graph,
			   int *i)
{
  game->charac = malloc(sizeof(t_char *) * (game->nb_char + 1));
  if (game->charac == NULL)
    return (-1);
  while (*i < game->nb_char)
    {
      game->charac[*i] = malloc(sizeof(t_char));
      if (game->charac[*i] == NULL)
	return (-1);
      game->charac[*i]->sprite = sfSprite_create();
      game->charac[*i]->texture =
	sfTexture_createFromFile(graph->characters.charac[*i], NULL);
      if (!(game->charac[*i]->texture))
	return (-1);
      sfSprite_setTexture(game->charac[*i]->sprite,
			  game->charac[*i]->texture, sfTrue);
      sfSprite_setPosition(game->charac[*i]->sprite,
			   get_pos_object(graph->characters.character,
					  *i + 1));
      (*i)++;
    }
  return (0);
}

int		init_zone(t_game *game, t_map *graph,
			  sfVector2f player_coord)
{
  int		i;

  if (init_values(game, graph, player_coord, &i) != 2)
    return (1);
  if (check_obj(game, graph, &i) != 0)
    return (1);
  game->nb_char = arr_len(graph->characters.charac);
  if (game->nb_char == 0)
    return (0);
  i = 0;
  if (check_char(game, graph, &i) != 0)
    return (1);
  return (0);
}
