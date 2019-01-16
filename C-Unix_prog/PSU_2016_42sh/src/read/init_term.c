/*
** init_term.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri May 19 12:32:12 2017 Thibaut Trouvé
** Last update Tue May 23 11:06:44 2017 dubret_v
*/

#include	<stdlib.h>
#include	<term.h>
#include	"read.h"

int		init_term(t_keys *keys)
{
  int		ret;
  char		*str;

  if (setupterm(NULL, 1, &ret) == -1)
    return (42);
  str = tigetstr("smkx");
  if (str == (char *) -1)
    return (84);
  if (str != NULL)
    my_putstr(str);
  if (init_keys(keys) == -1)
    return (84);
  return (0);
}
