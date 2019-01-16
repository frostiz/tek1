/*
** check_label_validity.c for corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 04:13:05 2017 
** Last update Sun Apr  2 11:14:57 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"

static int	is_existing_instruction(char *first_word)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcmp(op_tab[i].mnemonique, first_word) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		interpret_first_word(t_parse *parse)
{
  if (parse->first_word[0] == '\0')
    return (0);
  parse->idx_instruction = is_existing_instruction(parse->first_word);
  if (parse->idx_instruction >= 0)
    {
      if (check_instruction(parse) == 1)
	return (1);
    }
  else if (parse->first_word[my_strlen(parse->first_word) - 1] == LABEL_CHAR)
    {
      if (check_label(parse) == 1)
	return (1);
    }
  else if (parse->first_word[0] != '\0' &&
           my_strcmp(NAME_CMD_STRING, parse->first_word) != 0 &&
           my_strcmp(COMMENT_CMD_STRING, parse->first_word) != 0)
    {
      my_printf("Error line %d: Invalid instruction \"%s\".\n",
		parse->idx_line + 1, parse->first_word);
      return (1);
    }
  return (0);
}
