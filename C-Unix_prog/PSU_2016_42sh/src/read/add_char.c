/*
** add_char.c for add_char.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri May 19 14:23:19 2017 Vincent Roye
** Last update Sun May 21 18:10:07 2017 Thibaut Trouvé
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<term.h>
#include	<string.h>
#include	"read.h"

char		*add_char(char *str, int *cursor, char buff[])
{
  if (buff[0] == '\t' && buff[1] == '\0')
    {
      autocomplete(&str, cursor);
      return (str);
    }
  if ((int)strlen(str) == *cursor)
    {
      write(1, &buff[0], 1);
      str = realloc(str, strlen(str) + 8);
      str = strcat(str, buff);
    }
  else
    {
      if (buff[0] != '\n')
	{
	  my_putstr(tgetstr("im", NULL));
	  str = insert_char(str, *cursor, buff[0]);
	  write(1, &buff[0], 1);
	  my_putstr(tgetstr("ei", NULL));
	}
    }
  (*cursor)++;
  return (str);
}
