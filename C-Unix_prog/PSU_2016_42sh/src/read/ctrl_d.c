/*
** ctrl_d.c for ctrl_d.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 15:21:10 2017 Vincent Roye
** Last update Sun May 21 22:00:11 2017 Thibaut Trouvé
*/

#include	<stdlib.h>
#include	<string.h>
#include	<ncurses.h>
#include	<term.h>
#include	"read.h"

int		control_d(char *str, int *cursor)
{
  (void)str;
  (void)cursor;
  return (84);
}

int		control_g(char *str, int *cursor)
{
  (void)str;
  (void)cursor;
  return (0);
}

int		control_n(char *str, int *cursor)
{
  (void)str;
  (void)cursor;
  return (0);
}

int		control_o(char *str, int *cursor)
{
  (void)str;
  (void)cursor;
  return (0);
}

int		control_h(char *str, int *cursor)
{
  (void)str;
  (void)cursor;
  return (0);
}
