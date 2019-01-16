/*
** main.c for main.c in /home/frostiz/CPE_2016_Pushswap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 23 16:31:42 2016 thibaut trouve
** Last update Sun Nov 27 23:07:46 2016 thibaut trouve
*/

#include "my.h"

void	pushswap(t_lists lists, char **argv)
{
  lists.size_list_b = 0;
  lists.list_a = stock_arguments_in_list(lists.size_list_a, argv);
  lists.list_b = malloc(sizeof(int) * lists.size_list_a + 1);
  if (lists.list_b == NULL)
    return ;
  if (verif_sorted(lists.list_a, lists.size_list_a) == 1)
    return ;
  core_func(lists);
}

int	is_sorted(int *list_a, int size_list_a)
{
  int   i;

  i = 0;
  while (list_a[i] < list_a[i + 1])
    {
      if ((i == size_list_a - 1))
	{
	  my_putchar('\n');
	  return (1);
	}
      i++;
      if ((i == size_list_a - 1))
	{
	  my_putchar('\n');
	  return (1);
	}
    }
  return (0);
}

int	verif_sorted(int *list_a, int size_list_a)
{
  int   i;
  i = 0;
  if (size_list_a == 1)
    {
      my_putchar('\n');
      return (1);
    }
  if (is_sorted(list_a, size_list_a) == 1)
    return (1);
  if ((list_a[0] > list_a[1]) && (size_list_a == 2))
    {
      my_putstr("sa\n");
      return (1);
    }
  return (0);
}

int	main(int argc, char **argv)
{
  t_lists	lists;

  lists.size_list_a = argc - 1;
  pushswap(lists, argv);
  return (0);
}
