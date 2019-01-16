/*
** is_ever_passed.c for tekadventure in /home/DxCube/delivery/tekadventure/src/parsing
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 13:49:26 2017 Victor Dubret
** Last update Sun May 28 19:10:12 2017 Victor Dubret
*/

int		is_ever_passed(int nb, int *ever_passed)
{
  int		i;

  i = 1;
  while (i <= ever_passed[0])
    {
      if (nb == ever_passed[i])
	return (1);
      i++;
    }
  return (0);
}
