/*
** interpret_args.c for corewar in /home/thibaut/Repository/CPE_2016_corewar/asm/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  2 10:49:24 2017 Thibaut Trouvé
** Last update Sun Apr  2 21:16:50 2017 dubret_v
*/

#include "asm.h"
#include "my.h"

static int	check_after_nb(char *str, char *syntax)
{
  int	i;

  i = 0;
  if ((str[0] == '-' || str[0] == '+'))
    i++;
  while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    {
      my_printf("Error syntax with %s : %s\n", syntax, str);
      return (1);
    }
  return (0);
}

static int	check_register_validity(char **tab, int i,
					args_type_t *my_type, int *j)
{
  if (check_after_nb(&tab[i][1], "register") == 1)
    return (1);
  else if (my_getnbr(&tab[i][1]) <= 0 || my_getnbr(&tab[i][1]) > REG_NUMBER)
    {
      my_printf("Invalid register number : %s\n", tab[i]);
      return (1);
    }
  my_type[*j] = T_REG;
  (*j)++;
  return (0);
}

static int	check_direct_validity(char **tab, int i,
				     args_type_t *my_type, int *j)
{
  if (tab[i][1] == ':')
    {
      my_type[*j] = T_LAB;
      (*j)++;
    }
  else
    {
      my_type[*j] = T_DIR;
      (*j)++;
      if (check_after_nb(&tab[i][1], "direct type") == 1)
	return (1);
    }
  return (0);
}

static int	check_indirect_validity(char **tab, int i,
				       args_type_t *my_type, int *j)
{
  if (check_after_nb(tab[i], "indirect type") == 1)
    return (1);
  my_type[*j] = T_IND;
  (*j)++;
  return (0);
}

int		interpret_args(char **tab, args_type_t *my_type,
			       int i, int *j)
{
  if (tab[i][0] == 'r')
    {
      if (check_register_validity(tab, i, my_type, j) == 1)
	return (1);
    }
  else if (tab[i][0] == DIRECT_CHAR)
    {
      if (check_direct_validity(tab, i, my_type, j) == 1)
	return (1);
    }
  else if ((tab[i][0] >= '0' && tab[i][0] <= '9') ||
           tab[i][0] == '+' || tab[i][0] == '-')
    {
      if (check_indirect_validity(tab, i, my_type, j) == 1)
	return (1);
    }
  else
    {
      my_printf("Error: Invalid argument: %s\n", tab[i]);
      return (1);
    }
  return (0);
}
