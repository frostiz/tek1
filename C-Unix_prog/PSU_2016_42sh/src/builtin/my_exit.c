/*
** my_exit.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 18:42:08 2017 Lucas Dumy
** Last update Thu May 18 20:48:41 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	my_is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

void		my_exit(char **tab, __attribute__ ((unused)) char ***env,
			int *return_value, __attribute__ ((unused)) int *fd)
{
  int		is_num;

  if (tab[1] == NULL)
    *return_value = -2;
  else
    {
      is_num = my_is_num(tab[1]);
      if (is_num == 0 && tab[2] == NULL)
	*return_value = (atoi(tab[1]) + 2) * -1;
      else if ((is_num == 0 && tab[2] != NULL) ||
	       (tab[1][0] < '0' || tab[1][0] > '9'))
	my_perror("exit: Expression Syntax.\n");
      else if (is_num != 0)
	my_perror("exit: Badly formed number.\n");
    }
}
