/*
** sad_boss.c for sad_boss.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 08:12:19 2017 Vincent Roye
** Last update Sun May 28 20:57:59 2017 Vincent Roye
*/

#include        <SFML/Audio.h>
#include        <SFML/Graphics.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include	<time.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <fcntl.h>
#include        <math.h>
#include        <stdio.h>
#include        <string.h>
#include        "tekadventure.h"
#include        "my.h"

static void	do_animation(t_game *game, t_text2 *boss,
			     t_map *graph, int *i)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->wait_boss.sprite[0], NULL);
  sfRenderWindow_drawText(game->window, boss->text, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->up_walk.sprite[0], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
  *i = time(NULL);
  while (time(NULL) < *i + 2);
  second_anim(game);
  third_anim(game);
  boss->text_pos.x = 500;
  boss->text_pos.y = 600;
  sfText_setCharacterSize(boss->text, 20);
  sfText_setPosition(boss->text, boss->text_pos);
  sfText_setString(boss->text, "je suis a la recherche du cockpit"
		   "\nde mon vaisseau");
  refresh_screen(game, graph, *boss);
  *i = time(NULL);
  while (time(NULL) < *i + 2);
}

static void	do_second_animation(t_text2 *boss, t_game *game,
				    t_map *graph, int *i)
{
  boss->text_pos.x = 500;
  boss->text_pos.y = 250;
  sfText_setCharacterSize(boss->text, 20);
  sfText_setPosition(boss->text, boss->text_pos);
  sfText_setString(boss->text, "Ce gros engin derriere moi ?\n"
		   "il est tombe ici par la\ngrace de dieu,"
		   " il est a moi !");
  refresh_screen(game, graph, *boss);


  *i = time(NULL);
  while (time(NULL) < *i + 4);
  
}

static void	do_third_animation(int *i, t_game *game)
{
  int k;
  int j;

  k = 0;
  j = 0;
  while (*i < 6)
    {
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->attack_boss.sprite[*i],
				NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->up_walk.sprite[0], NULL);
      sfRenderWindow_display(game->window);
      j++;
      if (j == 40)
	{
	  k++;
	  j = 0;
	  (*i)++;
	}
      if (*i > 6)
	*i = 0;
    }
}

static void	finish(t_game *game)
{
  sfMusic	*music;
  sfTexture	*texture;
  sfSprite	*sprite;
  int		i;
  
  sprite = sfSprite_create();
  texture = sfTexture_createFromFile("pictures/wasted.png", NULL);
  if (texture == NULL)
    return ;
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfRenderWindow_drawSprite(game->window, sprite, NULL);
  sfRenderWindow_display(game->window);
  music = sfMusic_createFromFile("sounds/wasted.ogg");
  if (!(music))
    return ;
  sfMusic_play(music);
  i = time(NULL);
  while (time(NULL) < i + 4);
  sfMusic_destroy(music);
}

void		final_boss(t_game *game, t_map *graph)
{
  t_text2	boss;
  int		i;
  sfVector2f	pos;

  init_text_boss(&boss);
  sfMusic_pause(game->music);
  first_anim(game, graph);
  do_animation(game, &boss, graph, &i);
  do_second_animation(&boss, game, graph, &i);
  pos.x = 640;
  pos.y = 410;
  i = 0;
  while (i < 6)
    {
      sfSprite_setPosition(game->character->attack_boss.sprite[i],
			   pos);
      i++;
    }
  i = 0;
  do_third_animation(&i, game);
  finish(game);
}
