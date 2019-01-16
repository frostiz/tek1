/*
** my_strstr.c for Pool 06 in /home/H3r3zy/rendu/CPool_Day06
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Mon Oct 10 09:50:40 2016 Lucas Sahel
** Last update Fri Feb 17 09:00:12 2017 Sahel
*/

#include "basic.h"

char	*strstr_(char *str, char *to_find)
{
  int	str_len;
  int	to_find_len;
  int	i;
  int	j;
  int	find;

  str_len = strlen_(str);
  to_find_len = strlen_(to_find);
  i = 0;
  while (i < str_len)
    {
      j = 0;
      while (str[i + j] == to_find[j])
	{
	  if (j == to_find_len - 1)
	    find = i;
	  if (find != 0)
	    return (&str[find]);
	  j++;
	}
      i++;
    }
  if (find == 0)
    return (0);
  return (&str[find]);
}
