/*
** my_strcpy.c for Pool 06 in /home/H3r3zy/rendu/CPool_Day06
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Mon Oct 10 09:24:04 2016 Lucas Sahel
** Last update Fri Feb 17 08:57:21 2017 Sahel
*/

char	*strcpy_(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
