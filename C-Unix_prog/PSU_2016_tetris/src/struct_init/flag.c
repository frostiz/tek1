/*
** flag.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 16:15:20 2017 Sahel
** Last update Fri Mar  3 16:20:58 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

t_flag	init_flag(t_flag flag)
{
  flag.help = 0;
  flag.debug = 0;
  flag.without = 0;
  flag.kt = 0;
  flag.kl = 0;
  flag.kr = 0;
  flag.kp = 0;
  flag.kd = 0;
  flag.kq = 0;
  flag.level = 0;
  flag.mapsize = 0;
  flag.validity = 1;
  return (flag);
}
