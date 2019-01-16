/*
** free_.c for  in /home/sahel/rendu
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Feb 25 17:14:29 2017 Sahel
** Last update Sat Feb 25 17:33:22 2017 Sahel
*/

#include <stdlib.h>

void	free_(void *str)
{
  if (str)
    free(str);
}
