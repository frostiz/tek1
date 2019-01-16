/*
** game.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 16:20:31 2017 Sahel
** Last update Sun Mar 19 23:07:12 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <curses.h>
#include <time.h>
#include <term.h>
#include "main.h"
#include "basic.h"

static int	initial_key(t_datamap *game, char **env)
{
  char		*term;

  term = getenv_(env, "TERM=*");
  if (!term)
    return (84);
  if (setupterm(term, 1, (int *) 0) < 0)
    return (84);
  if ((game->key.drop = tigetstr("kcud1")) == (char *) -1 ||
      (game->key.right = tigetstr("kcuf1")) == (char *) -1 ||
      (game->key.turn = tigetstr("kcuu1")) == (char *) -1 ||
      (game->key.left = tigetstr("kcub1")) == (char *) -1)
    return (84);
  game->key.pause = strdup_(" ");
  if (game->key.pause == NULL)
    return (84);
  game->key.quit = strdup_("q");
  if (game->key.quit == NULL)
    return (84);
  return (0);
}

static int	initial_stats(t_datamap *game)
{
  game->stat.score = 0;
  game->stat.next_tetrimino = NULL;
  game->stat.chrono = clock();
  game->stat.cps = CLOCKS_PER_SEC;
  game->stat.line_deleted = 0;
  return (0);
}

t_datamap		*init_game(char **env)
{
  t_datamap		*game;

  if (!(game = malloc(sizeof(t_datamap))))
    return (NULL);
  if (initial_key(game, env) == 84)
    return (NULL);
  initial_stats(game);
  game->level = 1;
  game->map_size[0] = 20;
  game->map_size[1] = 10;
  game->without_next = 0;
  game->debug = 0;
  game->pause = 0;
  srand(time(NULL));
  game->random = rand() % 10;
  game->tetriminos = NULL;
  game->cl = CLOCKS_PER_SEC;
  game->time = clock() / game->cl;
  game->timeout = clock() / game->cl;
  game->stat.high_score = 0;
  return (game);
}
