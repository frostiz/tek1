/*
** boss_cinematic.c for boss_cinematic.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 18:06:36 2017 Vincent Roye
** Last update Sun May 28 18:57:11 2017 Vincent Roye
*/

#include	"tekadventure.h"

void		init_text_boss(t_text2 *boss)
{
  boss->text_pos.x = 550;
  boss->text_pos.y = 100;
  boss->font = sfFont_createFromFile("ttf/battlefield.ttf");
  boss->text = sfText_create();
  sfText_setCharacterSize(boss->text, 30);
  sfText_setFont(boss->text, boss->font);
  sfText_setString(boss->text, "QUI VA LA ?");
  sfText_setPosition(boss->text, boss->text_pos);
}

void		refresh_screen(t_game *game, t_map *graph,
			       t_text2 boss)
{
  (void)graph;
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->walk_boss.sprite[0], NULL);
  sfRenderWindow_drawText(game->window, boss.text, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->up_walk.sprite[0], NULL);
  print_object(game);
  sfRenderWindow_display(game->window);
}
