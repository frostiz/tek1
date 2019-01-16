/*
** modify_input.c for 42 in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri May 19 11:55:53 2017 Thibaut Trouvé
** Last update Sun May 21 19:21:55 2017 Vincent Roye
*/

#include	<string.h>
#include	<stdlib.h>

void		rem_char(char *str, int cursor)
{
  while (str[cursor] != '\0')
    {
      str[cursor] = str[cursor + 1];
      cursor++;
    }
}

void		del_char(char *str, int cursor)
{
  while (str[cursor] != '\0')
    {
      str[cursor] = str[cursor + 1];
      cursor++;
    }
}

char		*insert_char(char *str, int cursor, char c)
{
  int		max_len;
  int		end;

  max_len = (int)strlen(str);
  end = (int)strlen(str);
  str = realloc(str, strlen(str) + 8);
  while (max_len > cursor)
    {
      str[max_len] = str[max_len - 1];
      max_len--;
    }
  str[max_len] = c;
  str[end + 1] = '\0';
  return (str);
}
