/*
** cinematic.h for tekadventure in /home/frostiz/repository/tekadventure
**
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Wed May 24 12:31:51 2017 thibaut trouve
** Last update Sun May 28 13:00:25 2017 Vincent Roye
*/

#ifndef __CINEMATIC_H__
# define __CINEMATIC_H__
# define EXPLOSION_NB_SPRITE 15

#include "dialog.h"
#include "tekadventure.h"

typedef struct	s_img
{
  sfSprite	*sprite;
  sfTexture	*texture;
  t_attribute	attrib;
}		t_img;

typedef struct	s_cinematic
{
  sfRenderWindow	*win;
  t_img			*background;
  t_img			**explosion;
  t_img			*ship;
  t_img			*redhead;
  sfMusic		*explode;
  sfClock		*chrono;
}		t_cinematic;

typedef struct	s_end_cine
{
  sfSprite	*ship;
  sfTexture	*t_ship;
  sfVector2f	ship_pos;
  sfVector2f	ply_pos;
  sfVector2f	scale;
  int		i;
  int		j;
}		t_end_cine;

void		horizontal_move(t_end_cine *, t_game *);
void		vertical_move(t_end_cine *, t_game *);
int		set_env_cinematic(t_end_cine *);
int		end_game(t_game *, t_map *);
int		end_cinematique(t_game *);
int		launch_cinematic();
int		init_background(t_cinematic *);
int		init_explosion(t_cinematic *);
int		init_spaceship(t_cinematic *);
int		init_img(t_img *, char *);
int		first_scene(t_cinematic *);
int		second_scene(t_cinematic *);
int		fondu(t_cinematic *);

#endif /* !CINEMATIC_H */
