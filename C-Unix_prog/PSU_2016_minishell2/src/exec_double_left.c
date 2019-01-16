/*
** exec_double_left.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 03:30:31 2017 Thibaut Trouvé
** Last update Wed May  3 06:01:35 2017 Thibaut Trouvé
*/

#include "main.h"
#include "my.h"

int	is_left_double_redir(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], "<<") == 0)
	return (1);
      i++;
    }
  return (0);
}

int	exec_double_left(t_split *split, int *save_fd, t_tab **data)
{
  (void)split;
  (void)save_fd;
  (void)data;
  my_putstr("Not handled.\n");
  return (-1);
}
