/*
** happy_end3.c for happy_end3.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 20:26:33 2017 Vincent Roye
** Last update Sun May 28 20:37:59 2017 Vincent Roye
*/

#include	"tekadventure.h"

static void	print(t_game *game, int i, sfVector2f pos)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfSprite_setPosition(game->character->left_walk.sprite[i], pos);
  sfRenderWindow_drawSprite(game->window,
			    game->character->walk_boss.sprite[0], NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->left_walk.sprite[i], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
}

void		di_third_animation(t_game *game,
				   t_map *graph, t_text2 boss)
{
  int		i;
  int		j;
  sfVector2f	pos;

  pos.x = 640;
  pos.y = 520;
  i = 0;
  j  = 0;
  while (pos.y > 450)
    {
      print(game, i, pos);
      j++;
      if (j == 5)
	{
	  pos.x -= 0.5;
	  pos.y--;
	  j = 0;
	  i++;
	  if (i > 5)
	    i = 0;
	}
    }
  refresh_screen(game, graph, boss);
}
