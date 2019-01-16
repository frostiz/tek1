/*
** happy_end2.c for happy_end2.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 20:22:57 2017 Vincent Roye
** Last update Sun May 28 21:02:27 2017 Vincent Roye
*/

#include	"tekadventure.h"

static void	print(t_game *game, int i)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->walk_boss.sprite[0], NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->right_sword.sprite[i], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
}

void		di_fifth_animation(t_game *game)
{
  int		i;
  sfVector2f	pos;
  int		j;

  j = 0;
  pos.x = 600;
  pos.y = 400;
  i = 0;
  while (i < 6)
    {
      sfSprite_setPosition(game->character->right_sword.sprite[i],
			   pos);
      i++;
    }
  i = 0;
  while (i < 6)
    {
      print(game, i);
      j++;
      if (j == 20)
	{
	  j = 0;
	  i++;
	}
    }
}
