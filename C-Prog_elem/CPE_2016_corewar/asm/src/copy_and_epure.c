/*
** copy_and_epure.c for copy_and_epure.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 11:30:56 2017 Vincent Roye
** Last update Sun Apr  2 19:40:44 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void		epure_str(char **stock)
{
  int		line;
  int		i;

  line = 0;
  i = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  if (stock[line][i] == COMMENT_CHAR)
	    stock[line][i] = '\0';
	  i++;
	}
      i = 0;
      line++;
    }
}

char		*my_copy(char *str, int i)
{
  char		*tmp;
  int		j;

  j = 0;
  tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (tmp == NULL)
    my_error_exit("Error while allocating memory\n");
  while (i < my_strlen(COMMENT_CMD_STRING))
    {
      tmp[j] = str[j];
      j++;
      i++;
    }
  tmp[j] = '\0';
  return (tmp);
}
