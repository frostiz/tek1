/*
** tablen_.c for  in /home/sahel/rendu/PSU/PSU_2016_bstetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 21 09:48:22 2017 Sahel
** Last update Thu Mar  9 18:36:00 2017 Sahel
*/

int	tablen_(char **tab)
{
  int	len;

  len = 0;
  while (tab && tab[len])
    len++;
  return (len);
}
