/*
** my_epur_str.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sat May 13 18:53:42 2017 Lucas Dumy
** Last update Sun May 21 22:31:30 2017 bastien bedu
*/

#include	<string.h>
#include	<stdbool.h>
#include	"mysh.h"

static char	*tab_to_space(char *str)
{
  unsigned int	i;
  bool		quote;

  i = 0;
  quote = false;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	quote = !quote;
      if (quote == false)
	{
	  if (str[i] == '\t')
	    str[i] = ' ';
	}
      i++;
    }
  if (quote == true)
    {
      my_perror("Unmatched '\"'.\n");
      return (NULL);
    }
  return (str);
}

void		remove_character(char *str, unsigned int i)
{
  while (str[i + 1] != '\0')
    {
      str[i] = str[i + 1];
      i++;
    }
  str[i] = '\0';
}

static void	remove_double_char(char *str, char c)
{
  unsigned int	i;
  bool		quote;

  i = 0;
  quote = false;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	quote = !quote;
      if (quote == false)
	{
	  if (str[i] == c && str[i + 1] == c)
	    {
	      remove_character(str, i);
	      i--;
	    }
	}
      i++;
    }
}

void		remove_spare_spaces(char *str)
{
  unsigned int	i;
  bool		quote;

  i = 0;
  quote = false;
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] == '"')
	quote = !quote;
      if (quote == false)
	{
	  if (str[i] == ' ' && (i == 0 || str[i + 1] == '\0' ||
				(str[i + 1] == ';' && str[i - 1] == ';')))
	    {
	      remove_character(str, i);
	      i--;
	    }
	}
      i++;
    }
}

char		*my_epur_str(char *str, int *return_value)
{
  *return_value = 1;
  if (str == NULL)
    return (NULL);
  str = tab_to_space(str);
  if (str == NULL)
    return (NULL);
  remove_double_char(str, ' ');
  remove_spare_spaces(str);
  remove_double_char(str, ';');
  return_value = 0;
  return (str);
}
