/*
** count_separator.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 17:18:27 2017 Thibaut Trouvé
** Last update Sun Apr  9 22:17:38 2017 Thibaut Trouvé
*/

#include "my.h"
#include "main.h"

int	count_separator(char *input)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (input[i] != '\0')
    {
      if (is_alphanum(input[i]) == 0 && input[i] != '\0')
	count++;
      else if ((input[i] == '>' || input[i] == '<' ||
		input[i] == ';' || input[i] == '|')
	       && input[i] != '\0')
	count++;
      i++;
    }
  return (count);
}
