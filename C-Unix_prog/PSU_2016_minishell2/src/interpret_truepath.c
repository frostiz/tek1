/*
** interpret_truepath.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 05:54:13 2017 Thibaut Trouvé
** Last update Wed May  3 05:55:56 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

char	*interpret_truepath(char *paths)
{
  if (access(paths, F_OK) == 0 && access(paths, X_OK) == -1)
    return (paths);
  if (access(paths, X_OK) == 0)
    return (paths);
  free(paths);
  return (NULL);
}
