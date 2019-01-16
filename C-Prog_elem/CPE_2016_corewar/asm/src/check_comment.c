/*
** check_comment.c for check_comment.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 11:11:28 2017 Vincent Roye
** Last update Sun Apr  2 19:36:59 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int	check_multiple_comment(char *str)
{
  int	j;
  int	count;

  j = 0;
  count = 0;
  while (str[j] != '\0')
    {
      if (str[j] == '"')
	count++;
      j++;
    }
  if (count != 2)
    my_error_exit("multiple / wrong comment not allowed\n");
  return (0);
}

void	check_comment_line(char **stock, int line)
{
  int	i;

  i = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  if (stock[line][i] != '\0' &&
	                    stock[line][i] != ' ' &&
	      stock[line][i] != '\t')
	    {
	      if (stock[line][i] == COMMENT_CMD_STRING[0])
		{
		  my_copy(stock[line], i);
		  check_comment(stock[line]);
		  return ;
		}
	    }
	  i++;
	}
      i = 0;
      line++;
    }
}

int	check_comment(char *comment)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  check_multiple_comment(comment);
  while ((comment[i] != '\0' && comment[i] == ' ' ) ||
	 (comment[i] != '\0' && comment[i] == '\t'))
    i++;
  check_syntax(comment, i, my_strlen(COMMENT_CMD_STRING));
  tmp = malloc(sizeof(char) * (my_strlen(comment) + 1));
  if (tmp == NULL)
    return (1);
  while (comment[i] != '\0' && comment[i] != ' ' && comment[i] != '"')
    {
      tmp[j] = comment[i];
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strcmp(tmp, COMMENT_CMD_STRING) != 0)
    my_error_exit("Syntax error with .comment\n");
  return (0);
}
