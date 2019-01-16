/*
** my_str.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Tue May 16 17:47:46 2017 bastien bedu
** Last update Tue May 16 17:47:47 2017 bastien bedu
*/

#include	<stdlib.h>

char		*my_str_in_str(char *str_to_find, char *in_str)
{
  int		i;
  int		j;

  j = 0;
  while (in_str[j] != '\0')
    {
      i = 0;
      while (in_str[j] != '\0' && str_to_find[i] == in_str[j])
	{
	  i++;
	  j++;
	}
      if (str_to_find[i] == '\0' && str_to_find[0] != in_str[j])
	return (&str_to_find[j - i]);
      if (in_str[j] != '\0')
	j++;
    }
  return (NULL);
}
