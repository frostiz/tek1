/*
** puterror_.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  2 13:38:57 2017 Sahel
** Last update Thu Mar  2 13:39:35 2017 Sahel
*/

#include "basic.h"

int	puterror_(char *str, int fd)
{
  putstr_(str, fd);
  return (84);
}
