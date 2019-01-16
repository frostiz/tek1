/*
** error.c for raytrace in /home/thibaut/Repository/raytracer1
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 19:35:46 2017 
** Last update Sun Mar 19 23:28:50 2017 
*/

#include "my.h"

char	*get_var_env_value(char **my_env, char *var_name)
{
  int	i;
  int	j;
  char	*str;

  j = 0;
  i = 0;
  str = NULL;
  while (my_env[i] != NULL)
    {
      while (my_env[i][j] != '=' && my_env[i][j] != '\0')
	j++;
      if (my_strncmp(var_name, my_env[i], j) == 0)
	{
	  str = malloc(sizeof(char) * my_strlen(my_env[i]) + 1);
	  if (str == NULL)
	    return (NULL);
	  j++;
	  my_strcpy(str, &my_env[i][j]);
	}
      j = 0;
      i++;
    }
  if (str == NULL)
    return (NULL);
  return (str);
}
