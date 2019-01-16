/*
** debug.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Tue Mar  7 14:40:25 2017 Sahel
** Last update Thu Mar 16 09:20:21 2017 
*/

#include <sys/ioctl.h>
#include <term.h>
#include <unistd.h>
#include "main.h"
#include "basic.h"

void	putkey(char *key)
{
  int	key_i;

  key_i = 0;
  while (key && key[key_i])
    {
      if (key[key_i] == 27)
	putstr_("^E", 1);
      else if (key[key_i] == ' ')
	putstr_("(space)", 1);
      else
	write(1, &key[key_i], 1);
      key_i++;
    }
  write(1, "\n", 1);
}

int	debug(t_datamap *game)
{
  putstr_("*** DEBUG MODE ***\n", 1);
  putstr_("Key Left : ", 1);
  putkey(game->key.left);
  putstr_("Key Right : ", 1);
  putkey(game->key.right);
  putstr_("Key Turn : ", 1);
  putkey(game->key.turn);
  putstr_("Key Drop : ", 1);
  putkey(game->key.drop);
  putstr_("Key Quit : ", 1);
  putkey(game->key.quit);
  putstr_("Key Pause : ", 1);
  putkey(game->key.pause);
  putstr_("Next : ", 1);
  putstr_((game->without_next == 1) ? ("No\n") : ("Yes\n"), 1);
  putstr_("Level : ", 1);
  putnbr_(game->level);
  putstr_("\nSize : ", 1);
  putnbr_(game->map_size[0]);
  putstr_("*", 1);
  putnbr_(game->map_size[1]);
  putstr_("\n", 1);
  return (0);
}
