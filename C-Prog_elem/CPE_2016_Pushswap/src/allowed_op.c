/*
** allowed_op.c for allowed_op.c in /home/frostiz/CPE_2016_Pushswap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Nov 21 01:09:14 2016 thibaut trouve
** Last update Sun Nov 27 23:06:53 2016 thibaut trouve
*/

#include "my.h"

void	rotate_right(int *array, int size)
{
  int   i;
  int   tmp;

  i = 0;
  tmp = array[size - 1];
  while (size > 1)
    {
      array[size - 1] = array[size-2];
      size--;
    }
  array[0] = tmp;
}

void	rotate_left(int *array, int size)
{
  int   i;
  int   tmp;

  i = 0;
  tmp = array[0];
  while (i < size - 1)
    {
      array[i] = array[i + 1];
      i++;
    }
  array[size - 1] = tmp;
}

void	shift_right(int *list2, int size)
{
  int	tmp;

  while (size >= 1)
    {
      tmp = list2[size - 1];
      list2[size] = tmp;
      size--;
    }
  if (size != 1)
  list2[0] = 0;
}

void	shift_left(int *list1, int size)
{
  int	i;
  int	tmp;

  i = 0;
  while (i < size - 1)
    {
      tmp = list1[i + 1];
      list1[i] = tmp;
      i++;
    }
  if (size != 1)
    list1[size - 1] = 0;
}

t_lists	push_a_to_b(t_lists lists)
{
  int   tmp;

  tmp = lists.list_a[0];
  shift_left(lists.list_a, lists.size_list_a);
  if (lists.size_list_a > 0)
    {
      shift_right(lists.list_b, lists.size_list_b);
      lists.list_b[0] = tmp;
    }
  else
    {
      lists.list_b[0] = tmp;
    }
  lists.size_list_b++;
  lists.size_list_a--;
  return (lists);
}
