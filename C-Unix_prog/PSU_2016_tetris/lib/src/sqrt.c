/*
** sqrt.c for  in /home/sahel/bin/lib/src
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:13:01 2017 Sahel
** Last update Fri Feb 17 08:13:03 2017 Sahel
*/

int	sqrt_(int nb)
{
  int	i;

  i = 1;
  if (nb <= 0)
    return (0);
  while (i * i <= nb)
    {
      if (i * i == nb)
	return (i);
      i++;
    }
  return (0);
}
