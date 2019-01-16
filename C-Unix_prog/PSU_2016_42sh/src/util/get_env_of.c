/*
** get_env_of.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 12:40:15 2017 bastien bedu
** Last update Sat May 20 14:33:49 2017 bastien bedu
*/

#include	<stdlib.h>
#include	"mysh.h"
#include	"env.h"

int		get_env_of(char *str, int nb_var, char **env, char **result)
{
  char		*var;
  int		j;

  j = 0;
  while (is_char_alphanum(str[j]) == 1)
    j++;
  var = my_strdup_to(str, j);
  result[nb_var] = value_of(env, var);
  if (result[nb_var] == NULL)
    {
      my_free_tab(result);
      if (var == NULL || var[0] == '\0')
	my_perror("Illegal variable name.\n");
      else
	{
	  my_perror(var);
	  my_perror(": Undefined variable.\n");
	}
      free(var);
      return (0);
    }
  free(var);
  return (1);
}
