/*
** my_strcmp.c for Pool 06 in /home/H3r3zy/rendu/CPool_Day06
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Mon Oct 10 13:05:19 2016 Lucas Sahel
** Last update Fri Mar 10 20:54:16 2017 
*/

#include "basic.h"

int	strncmp_(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
    i++;
  return (s1[i] - s2[i]);
}
