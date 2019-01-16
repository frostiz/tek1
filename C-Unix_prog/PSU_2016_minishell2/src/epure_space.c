/*
** epure_space.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 06:02:35 2017 Thibaut Trouvé
** Last update Wed May  3 06:16:00 2017 Thibaut Trouvé
*/

#include "main.h"
#include "my.h"

static void	remove_space_begin(char *str)
{
  int	i;

  while (str[0] == ' ')
    {
      i = 0;
      while (str[i] != '\0')
	{
	  str[i] = str[i + 1];
	  i++;
	}
    }
}

static void	remove_space_end(char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      j = i;
      while (str[j] != '\0' && str[j] == ' ')
	j++;
      if (str[j] == '\0')
	str[i] = '\0';
      i++;
    }
}

void	epure_space(char *str)
{
  int	i;

  remove_space_begin(str);
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
          (str[i + 1] == ' ' || str[i + 1] == '\t'))
	{
	  while (str[i] != '\0')
	    {
	      str[i] = str[i + 1];
	      i++;
	    }
	  i = -1;
	}
      i++;
    }
  remove_space_end(str);
}
