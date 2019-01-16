/*
** swap.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Fri May 19 14:10:54 2017 bastien bedu
** Last update Fri May 19 14:12:00 2017 bastien bedu
*/

void		my_swap(char **str1, char **str2)
{
  char		*tmp;

  tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}
