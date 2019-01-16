/*
** happy_end1.c for happy1.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 20:14:35 2017 Vincent Roye
** Last update Sun May 28 20:34:19 2017 Vincent Roye
*/

#include	<time.h>
#include	"tekadventure.h"
#include	"character.h"

static void	print(t_game *game, int i)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->boss_death.sprite[i], NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->right_walk.sprite[0], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
}

static void	init_values(int *i, int *j, sfVector2f *pos)
{
  *j = 0;
  pos->x = 620;
  pos->y = 400;
  *i = 0;
}

void		do_sixth_animation(t_game *game)
{
  sfVector2f	pos;
  int		i;
  int		j;

  init_values(&i, &j, &pos);
  while (i < 6)
    {
      sfSprite_setPosition(game->character->boss_death.sprite[i],
			   pos);
      i++;
    }
  i = 0;
  while (i < 6)
    {
      print(game, i);
      j++;
      if (j == 25)
	{
	  j = 0;
	  i++;
	}
    }
  i = time(NULL);
  while (time(NULL) < i + 4);
}
