/*
** my_is_prime.c for my_is_prime in /home/H3r3zy/rendu/Day05
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Fri Oct  7 11:14:46 2016 Lucas Sahel
** Last update Fri Feb 17 08:20:46 2017 Sahel
*/

int	is_prime(int nb)
{
  int	i;

  if (nb <= 1)
    return (0);
  i = 2;
  while (nb % i != 0)
    i++;
  if (i == nb)
    return (1);
  else
    return (0);
}
