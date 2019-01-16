/*
** check_label.c for Corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 04:30:52 2017 
** Last update Sun Apr  2 11:14:32 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"

static int	check_label_chars(char *first_word, int idx_line)
{
  int		i;
  int		j;
  int		char_found;

  j = 0;
  i = 0;
  while (first_word[i + 1] != '\0')
    {
      j = 0;
      char_found = 0;
      while (LABEL_CHARS[j] != '\0')
	{
	  if (LABEL_CHARS[j] == first_word[i])
	    char_found = 1;
	  j++;
	}
      if (char_found == 0)
	{
	  my_printf("Error line %d: Invalid character found \"%c\".\n",
		    idx_line + 1, first_word[i]);
	  return (1);
	}
      i++;
    }
  return (0);
}

int		check_label(t_parse *parse)
{
  if (check_label_chars(parse->first_word, parse->idx_line) == 1)
    return (1);
  return (0);
}
