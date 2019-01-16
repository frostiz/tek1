/*
** check_name.c for check_name.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 11:17:51 2017 Vincent Roye
** Last update Sun Apr  2 11:29:11 2017 Vincent Roye
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int	check_name(char *str, int i)
{
  char	*tmp;
  int	j;

  j = 0;
  i = 0;
  while ((str[i] != '\0' && str[i] == ' ' ) ||
	 (str[i] != '\0' && str[i] == '\t'))
    i++;
  check_multiple_comment(str);
  check_syntax(str, i, my_strlen(NAME_CMD_STRING));
  tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (tmp == NULL)
    return (1);
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '"')
    {
      tmp[j] = str[i];
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strcmp(tmp, NAME_CMD_STRING) != 0)
    my_error_exit("Syntax error with .name\n");
  return (0);
}
