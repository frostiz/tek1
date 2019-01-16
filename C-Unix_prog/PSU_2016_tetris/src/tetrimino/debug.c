/*
** debug.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 18 16:35:11 2017 Sahel
** Last update Sat Mar 18 16:41:18 2017 Sahel
*/

#include "main.h"
#include "basic.h"

void	call_new_tetri(t_datamap *game, char *path)
{
  if (game->debug == 1)
    {
      putstr_("Tetriminos : Name ", 1);
      putstr_(take_name(path), 1);
      putstr_(" : ", 1);
    }
  if (new_tetrimino(game, path) == 84 && game->debug == 1)
    putstr_("Error\n", 1);
}
