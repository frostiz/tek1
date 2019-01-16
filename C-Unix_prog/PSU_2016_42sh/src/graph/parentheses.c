/*
** parentheses.c for 42sh$ in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Fri May 19 20:28:18 2017 dubret_v
** Last update Sun May 21 21:46:13 2017 dubret_v
*/

#include		<string.h>
#include		<stdlib.h>
#include		"mysh.h"

static	int		first_check(char *str)
{
  int			i;
  int			nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	nb++;
      else if (str[i] == ')')
	nb--;
      if (str[i] == '"' || str[i] == '`')
	i = go_through_quotes(str, i + 1, str[i]);
      else
	i++;
      if (nb < 0)
	return (my_put_error("Too many )'s.\n", 84));
    }
  if (nb > 0)
    return (my_put_error("Too many ('s.\n", 84));
  return (0);
}

int			only_parentheses(char *str)
{
  int			i;
  int			nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '(' && str[i] != ')')
	return (0);
      if (str[i] == '(')
	nb++;
      else if (str[i] == ')')
	{
	  nb--;
	  if (nb == 0 && str[i + 1] == '\0')
	    {
	      my_perror("Invalid null command.\n");
	      return (84);
	    }
	  else if (nb == 0)
	    return (0);
	}
      i++;
    }
  return (0);
}

/*
** 1 on peux remove 0 on peut pas.
*/
int			is_only_parentheses(char *str)
{
  int			i;
  int			remove_parentheses;

  i = 0;
  remove_parentheses = 0;
  if (only_parentheses(str) == 84)
    return (84);
  if (first_check(str) == 84)
    return (84);
  if (str[0] == '(')
    {
      remove_parentheses = 1;
      i++;
    }
  while (remove_parentheses != 0 && str[i] != '\0')
    {
      if (str[i] == '(')
	remove_parentheses += 1;
      else if (str[i] == ')')
	remove_parentheses -= 1;
      i++;
    }
  if (str[i] == '\0' && remove_parentheses == 0)
    remove_parentheses = 1;
  return (remove_parentheses);
}
