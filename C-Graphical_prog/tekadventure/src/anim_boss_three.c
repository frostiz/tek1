/*
** anim_boss_three.c for anim_boss_three.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 18:02:53 2017 Vincent Roye
** Last update Sun May 28 22:04:12 2017 Victor Dubret
*/

#include	"tekadventure.h"

static void	incr_values(int *j, int *i, sfVector2f *pos)
{
  (*j)++;
  if (*j == 10)
    {
      *j = 0;
      (*i)++;
    }
  if (*i > 8)
    *i = 0;
  pos->y -= 1;
}

void		 third_anim(t_game *game)
{
  sfVector2f	pos;
  int		i;
  int		j;

  pos.x = 640;
  pos.y = 620;
  j = 0;
  i = 0;
  while (pos.y > 500)
    {
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfSprite_setPosition(game->character->up_walk.sprite[i], pos);
      sfRenderWindow_drawSprite(game->window,
				game->character->walk_boss.sprite[0], NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->up_walk.sprite[i], NULL);
      print_object(game);
      sfRenderWindow_display(game->window);
      incr_values(&j, &i, &pos);
    }
}
