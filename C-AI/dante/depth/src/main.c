/*
** main.c for depth in /home/thibaut/Repository/dante/solver/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May 10 18:17:49 2017 Thibaut Trouvé
** Last update Wed May 10 18:24:52 2017 Thibaut Trouvé
*/

#include "depth.h"

int	main(int ac, char **av)
{
  if (ac != 2)
    return (84);
  if (depth(av[1]) == 84)
    return (84);
  return (0);
}
