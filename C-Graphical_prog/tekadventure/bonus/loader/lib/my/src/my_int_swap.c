/*
** my_int_swap.c for my_int_swap.c in /home/roye_v/delivery/raytracer1/src/my/lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 19:19:01 2017 Vincent Roye
** Last update Sat Feb 11 19:19:54 2017 Vincent Roye
*/

int	my_int_swap(int *a, int *b)
{
  int	c;

  c = 0;
  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
