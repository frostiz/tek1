/*
** happy_boss.c for happy_boss.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 19:05:11 2017 Vincent Roye
** Last update Sun May 28 21:15:40 2017 Vincent Roye
*/

#include        <SFML/Audio.h>
#include        <SFML/Graphics.h>
#include	<time.h>
#include        <unistd.h>
#include        <stdlib.h>
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

static void	do_fourth_animation(t_game *game, t_map *graph, t_text2 *boss)
{
  sfVector2f	pos;
  int		i;

  (void)graph;
  pos.x = 610;
  pos.y = 450;
  boss->text_pos.x = 500;
  boss->text_pos.y = 250;
  sfText_setCharacterSize(boss->text, 20);
  sfText_setPosition(boss->text, boss->text_pos);
  sfText_setString(boss->text, "J'ai une surprise pour toi !");
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfSprite_setPosition(game->character->right_walk.sprite[0], pos);
  sfRenderWindow_drawText(game->window, boss->text, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->walk_boss.sprite[0], NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->right_walk.sprite[0], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
  i = time(NULL);
  while (time(NULL) < i + 4);
}

void		final_boss_win(t_game *game, t_map *graph)
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
  di_third_animation(game, graph, boss);
  do_fourth_animation(game, graph, &boss);
  di_fifth_animation(game);
  do_sixth_animation(game);
}
