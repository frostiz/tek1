/*
** read_next_line.c for read_next_line.c in /home/roye_v/delivery/CPE_2016_n4s
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Jun  2 15:16:22 2017 Vincent Roye
** Last update Fri Jun  2 15:16:23 2017 Vincent Roye
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"n4s.h"

int		check_read(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char		*my_strcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
  if (tmp == NULL)
    return (NULL);
  while (s1[i] != '\0')
    {
      tmp[i] = s1[i];
      i++;
    }
  while (s2[j] != '\0')
    {
      tmp[i] = s2[j];
      i++;
      j++;
    }
  tmp[i] = '\0';
  free(s1);
  return (tmp);
}

char		*read_next_line()
{
  char		buff[1];
  char		*str;
  int		size;
  int		len;

  len = 1;
  str = malloc(sizeof(char));
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  while ((size = read(0, buff, len)) != -1)
    {
      buff[size] = '\0';
      str = my_strcat(str, buff);
      if (check_read(buff) == 1)
	{
	  if (my_strlen(str) > 1)
	    str[my_strlen(str) - 1] = '\0';
	  else
	    str[0] = '\0';
	  return (str);
	}
    }
  return (NULL);
}
