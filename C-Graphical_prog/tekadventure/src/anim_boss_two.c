/*
** anim_boss_two.c for anim_boss_two.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 17:56:14 2017 Vincent Roye
** Last update Sun May 28 22:07:50 2017 Victor Dubret
*/

#include	"tekadventure.h"

static void	init_values(int *i, int *j, t_game *game,
			    sfVector2f *pos)
{
  pos->x = 640;
  pos->y = 250;
  *i = 0;
  *j = 0;
  while (*i < 9)
    {
      sfSprite_setPosition(game->character->walk_boss.sprite[*i], *pos);
      (*i)++;
    }
  *i = 0;
}

void		second_anim(t_game *game)
{
  sfVector2f	pos;
  int	        i;
  int		j;

  init_values(&i, &j, game, &pos);
  while (pos.y < 450)
    {
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfSprite_setPosition(game->character->walk_boss.sprite[i], pos);
      sfRenderWindow_drawSprite(game->window,
				game->character->walk_boss.sprite[i], NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->up_walk.sprite[0], NULL);
      sfRenderWindow_display(game->window);
      j++;
      if (j == 10)
	{
	  j = 0;
	  i++;
	}
      if (i > 8)
	i = 0;
      pos.y += 1;
    }
}
