/*
** my_putstr.c for my_putstr in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 22:13:29 2017 Thibaut Trouvé
** Last update Mon Apr  3 22:14:14 2017 Thibaut Trouvé
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(1, &str[i], 1);
      i++;
    }
}
