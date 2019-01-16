/*
** power.c for  in /home/sahel/bin/lib/src
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:06:09 2017 Sahel
** Last update Fri Feb 17 08:29:27 2017 Sahel
*/

int	power_(int nb, int p)
{
  int	snb;

  snb = nb;
  if (p == 0)
    return (1);
  while (p-- > 1)
    nb *= snb;
  return (nb);
}
