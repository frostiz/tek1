/*
** my_putstr_err.c for raytrace in /home/thibaut/Repository/raytracer1
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 19:41:06 2017 
** Last update Sun Mar 19 19:41:55 2017 
*/

#include <unistd.h>

void	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write (2, &str[i], 1);
      i++;
    }
}
