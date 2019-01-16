/*
** check_instruction_arg.c for Corewar in /home/thibaut/Repository/CPE_2016_corewar/asm/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  2 10:41:53 2017 Thibaut Trouvé
** Last update Sun Apr  2 21:15:59 2017 dubret_v
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"

static int	link_to_check_args_type(int idx, t_parse *parse,
					args_type_t *my_type)
{
  t_type type;

  if (check_args_type(idx, parse->idx_instruction, init_reg(type)) == 1
      && my_type[idx] == T_REG)
    {
      my_printf("1 Error line %d: Invalid arg %d for \"%s\" instruction\n",
                parse->idx_line + 1, idx, parse->instruction);
      return (1);
    }
  else if (check_args_type(idx, parse->idx_instruction, init_dir(type))
           == 1 && (my_type[idx] == T_DIR || my_type[idx] == T_LAB))
    {
      my_printf("2 Error line %d: Invalid arg %d for \"%s\" instruction\n",
		parse->idx_line + 1, idx + 1, parse->instruction);
      return (1);
    }
  else if (check_args_type(idx, parse->idx_instruction, init_ind(type))
           == 1 && my_type[idx] == T_IND)
    {
      my_printf("3 Error line %d: Invalid arg %d for \"%s\" instruction\n",
                parse->idx_line + 1, idx + 1, parse->instruction);
      return (1);
    }
  return (0);
}

static int	compare_type(t_parse *parse, args_type_t *my_type)
{
  int		i;

  i = 0;
  while (my_type[i] != '\0')
    {
      if (link_to_check_args_type(i, parse, my_type) == 1)
	return (1);
      i++;
    }
  return (0);
}

static int	check_args_in_tab(char **tab, t_parse *parse)
{
  args_type_t	*my_type;
  int		i;
  int		j;

  i = 1;
  j = 0;
  my_type = malloc(sizeof(char) * MAX_ARGS_NUMBER + 1);
  if (my_type == NULL)
    return (1);
  while (tab[i] != NULL)
    {
      if (my_strlen(tab[i]) >= 1)
	if (interpret_args(tab, my_type, i, &j) == 1)
	  return (1);
      i++;
    }
  my_type[j] = '\0';
  if (compare_type(parse, my_type) == 1)
    return (1);
  return (0);
}

static int	check_nb_arg(char **tab)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (tab[i] != NULL)
    i++;
  if (i == 0)
    return (1);
  while (op_tab[j].mnemonique != 0)
    {
      if (my_strncmp(op_tab[j].mnemonique, tab[0],
		     my_strlen(op_tab[j].mnemonique)) == 0)
	{
	  if (op_tab[j].nbr_args != i - 1)
	    return (1);
	}
      j++;
    }
  return (0);
}

int	check_instruction_arg_validity(t_parse *parse)
{
  char **tab;

  tab = my_str_to_wordtab(&parse->line[0],
                          SEPARATOR_CHAR);
  if (tab == NULL)
    return (1);
  if (check_nb_arg(tab) == 1)
    return (1);
  if (check_args_in_tab(tab, parse) == 1)
    return (1);
  return (0);
}
