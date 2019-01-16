/*
** check_instruction.c for Corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 04:29:31 2017 Thibaut Trouvé
** Last update Sun Apr  2 19:29:58 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"

static int	check_instruction_nb_args(t_parse *parse)
{
  int		nb_args;
  int		nb_separator;
  int		i;

  i = 0;
  nb_separator = 0;
  while (parse->line[i] != '\0')
    {
      if (parse->line[i] == SEPARATOR_CHAR)
	nb_separator++;
      i++;
    }
  nb_args = nb_separator + 1;
  if (nb_args != op_tab[parse->idx_instruction].nbr_args ||
      nb_args > MAX_ARGS_NUMBER)
    {
      my_printf("Error line %d: Too many arguments given to the\
 instruction.\n", parse->idx_line + 1);
      return (1);
    }
  return (0);
}

int		check_args_type(int idx, int idx_instruction, t_type type)
{
  if (op_tab[idx_instruction].type[idx] != type.a &&
      op_tab[idx_instruction].type[idx] != type.a + type.b &&
      op_tab[idx_instruction].type[idx] != type.a + type.c &&
      op_tab[idx_instruction].type[idx] != type.a + type.c + type.b)
    return (1);
  return (0);
}

int		check_instruction(t_parse *parse)
{
  parse->instruction = op_tab[parse->idx_instruction].mnemonique;
  if (check_instruction_nb_args(parse) == 1)
    return (1);
  if (check_instruction_arg_validity(parse) == 1)
    return (1);
  return (0);
}
