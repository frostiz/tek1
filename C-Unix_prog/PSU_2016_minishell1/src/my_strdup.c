/*
** my_strdup.c for my_strdup.c in /home/frostiz/CPool_Day08/task01
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Oct 12 09:28:27 2016 thibaut trouve
** Last update Tue Jan 24 15:11:57 2017 thibaut trouve
*/

#include "get_next_line.h"
#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*str;

  str = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (str == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	*clearstr(t_str *strings, char *remain, t_pos *pos)
{
  if (my_strcpy_len(strings->str, remain, pos, '\n') == -3)
    return (clean_fill_remain(strings, remain, pos, 0));
  else if (remain[0] != '\0')
    {
      remain[0] = '\0';
      pos->dest = my_strcpy_len(strings->str, strings->str, pos, 1);
      pos->src = 0;
      return (strings->str);
    }
  return (NULL);
}
