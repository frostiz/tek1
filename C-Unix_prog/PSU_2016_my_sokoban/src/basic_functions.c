/*
** basic_functions.c for basic_functions.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Dec 15 23:55:57 2016 thibaut trouve
** Last update Sat Dec 17 17:48:37 2016 thibaut trouve
*/

#include "my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

void	swap(char *a, char *b)
{
  char tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void	make_window(void)
{
  initscr();
  raw();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
}
