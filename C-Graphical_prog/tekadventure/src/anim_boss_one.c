/*
** ending1.c for ending1.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 17:45:41 2017 Vincent Roye
** Last update Sun May 28 18:52:27 2017 Vincent Roye
*/

#include	"tekadventure.h"

static void	init_pos(t_game *game, int *i, int *j)
{
  sfVector2f	pos;
  *i = 0;
  *j = 0;
  pos.x = 640;
  pos.y = 200;
  while (*i < 7)
    {
      sfSprite_setPosition(game->character->wait_boss.sprite[*i],
			   pos);
      (*i)++;
    }
  *i = 0;
}

static void	incr_values(int *i, int *j, int *three_time)
{
  (*j)++;
  if (*i == 6)
    *i = 0;
  if (*j == 13)
    {
      (*three_time)++;
      (*i)++;
      *j = 0;
    }
}

void		first_anim(t_game *game, t_map *graph)
{
  int		i;
  int		j;
  int		three_time;

  (void)graph;
  init_pos(game, &i, &j);
  three_time = 0;
  while (three_time != 15)
    {
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->wait_boss.sprite[i], NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->up_walk.sprite[0], NULL);
      print_object(game);
      sfRenderWindow_display(game->window);
      incr_values(&i, &j, &three_time);
    }
}
