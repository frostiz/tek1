/*
** pushswap.c for pushswap.c in /home/frostiz/CPE_2016_Pushswap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 21 13:21:13 2016 thibaut trouve
** Last update Sun Nov 27 23:08:00 2016 thibaut trouve
*/

#include "my.h"

int	search_smaller(int *list_a, int size_list_a, int *j)
{
  int	i;
  int	tmp;

  i = 0;
  while (i < size_list_a)
    {
      if (list_a[i] > tmp)
	{
	  tmp = list_a[i];
	}
      i++;
    }
  i = 0;
  while (i < size_list_a)
    {
      if (list_a[i] < tmp)
	{
	tmp = list_a[i];
	*j = i;
	}
      i++;
    }
  return (tmp);
}

void	stock_type(char buffer[], int type, int *size)
{
  if (type == 3)
    {
      buffer[*size] = 'p';
      (*size)++;
      buffer[*size] = 'b';
      (*size)++;
      buffer[*size] = ' ';
      (*size)++;
    }
  if (type == 4)
    {
      buffer[*size] = 'p';
      (*size)++;
      buffer[*size] = 'a';
      (*size)++;
    }
  if (*size >= 29900)
    {
      write(1, buffer, *size);
      *size = 0;
    }
}

void	stock_buff(char buffer[], int type, int *size)
{
  if (type == 1 || type == 2)
    {
      buffer[*size] = 'r';
      (*size)++;
      if (type == 2)
	{
	  buffer[*size] = 'r';
	  (*size)++;
	}
      buffer[*size] = 'a';
      (*size)++;
      buffer[*size] = ' ';
      (*size)++;
    }
  stock_type(buffer, type, size);
}

t_lists	empty_a(t_lists lists, char buffer[], int *size)
{
  int tmp;
  int position;

  tmp = search_smaller(lists.list_a, lists.size_list_a, &position);
  while (lists.list_a[0] != tmp)
    {
      if (position < lists.size_list_a / 2)
	{
	      stock_buff(buffer, 1, size);
	      rotate_left(lists.list_a, lists.size_list_a);
	}
      else
	{
	      stock_buff(buffer, 2, size);
	      rotate_right(lists.list_a, lists.size_list_a);
	}
    }
  lists = push_a_to_b(lists);
  stock_buff(buffer, 3, size);
  return (lists);
}

void	core_func(t_lists lists)
{
  char	buffer[30000];
  int	size;
  size = 0;

  while (lists.size_list_a > 0)
    lists = empty_a(lists, buffer, &size);
  while (lists.size_list_b > 0)
    {
      lists.size_list_b--;
      lists.size_list_a++;
      stock_buff(buffer, 4, &size);
      if (lists.size_list_a > 0 && lists.size_list_b > 0)
	{
	  buffer[size] = ' ';
	  size++;
	}
      else if (size < 30000 && lists.size_list_b == 0)
	{
	  write(1, buffer, size);
	  write(1, "\n", 1);
	}
    }
}
