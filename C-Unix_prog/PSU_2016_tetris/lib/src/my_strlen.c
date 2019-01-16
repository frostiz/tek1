/*
** my_putstr.c for my_putstr in /home/H3r3zy/rendu/CPool_Day04
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Thu Oct  6 09:43:44 2016 Lucas Sahel
** Last update Fri Feb 17 08:18:35 2017 Sahel
*/

int	strlen_(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
