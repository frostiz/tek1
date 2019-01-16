/*
** help.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 14:39:35 2017 Sahel
** Last update Fri Mar 17 14:47:59 2017 Sahel
*/

#include <unistd.h>
#include "basic.h"

int	help(char *str, int ret)
{
  putstr_("Usage:  ", 1);
  putstr_(str, 1);
  putstr_(" [options]\n", 1);
  write(1, "Options:\n  ", 11);
  write(1, "--help                Display the help\n", 39);
  write(1, "  -l --level={num}      ", 24);
  write(1, "Start Tetris at level num (def:  1)\n", 36);
  write(1, "  -kl --key-left={K}    Move the tetrimino LEFT using the", 57);
  write(1, " K key (def:  left arrow)\n", 26);
  write(1, "  -kr --key-right={K}   Move the tetrimino RIGHT using the ", 59);
  write(1, "K key (def:  right arrow)\n", 26);
  write(1, "  -kt --key-turn={K}    TURN the tetrimino clockwise 90d", 48);
  write(1, " using the K key (def:  top arrow)\n", 35);
  write(1, "  -kd --key-drop={K}    DROP the tetrimino using the K key ", 59);
  write(1, "(def:  down arrow)\n", 19);
  write(1, "  -kq --key-quit={K}    QUIT the game using the K key ", 54);
  write(1, "(def:  'Q' key)\n", 16);
  write(1, "  -kp --key-pause={K}   PAUSE/RESTART the game using the K ", 59);
  write(1, "key (def:  space bar)\n", 22);
  write(1, "  --map-size={row,col}  Set the numbers of rows and ", 52);
  write(1, "columns of the map (def:  20,10)\n", 33);
  write(1, "  -w --without-next     Hide next tetrimino (def:  false)\n", 58);
  write(1, "  -d --debug            Debug mode (def:  false)\n", 49);
  return (ret);
}
