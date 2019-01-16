/*
** flags_left.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 15:24:41 2017 Sahel
** Last update Tue Mar  7 18:07:03 2017 Sahel
*/

#include "main.h"

int		flags_debug(char **av, int *ac, t_datamap *game)
{
  (void)	av;
  (void)	ac;
  game->debug = 1;
  return (0);
}
