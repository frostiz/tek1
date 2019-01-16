/*
** syntax_error.c for syntax_error.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 11:21:50 2017 Vincent Roye
** Last update Sun Apr  2 11:27:23 2017 Vincent Roye
*/

#include "op.h"
#include "asm.h"

static void	init_string(char *str, int *i)
{
  while ((str[*i] != '\0' && str[*i] == ' ') ||
	 (str[*i] != '\0' && str[*i] == '\t'))
    (*i)++;
}

void	check_syntax(char *str, int i, int lenght)
{
  int	comment;

  i = 0;
  init_string(str, &i);
  i += lenght;
  comment = 0;
  while (str[i] != '\0' && str[i] != '"')
    {
      if (str[i] != ' ' && str[i] != '\t')
	my_error_exit("Syntax error\n");
      i++;
    }
  i = 0;
  while (str[i] != '\0' && comment != 2)
    {
      if (str[i] == '"')
	comment++;
      i++;
    }
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	my_error_exit("Syntax error\n");
      i++;
    }
}
