/*
** my_getnbr.c for my_getnbr.c in /home/roye_v/delivery/my_lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 18:24:37 2017 Vincent Roye
** Last update Sat Feb 11 18:26:08 2017 Vincent Roye
*/

int	my_getnbr(char *str)
{
  int	sign;
  int	res;

  sign = 1;
  res = 0;
  while (*str == '-')
    {
      if (*str == '-')
	sign = -sign;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      res = res * 10 + *str - 48;
      str = str + 1;
    }
  if (sign == -1)
    res = -res;
  return (res);
}
