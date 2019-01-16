/*
** my_strcpy.c for my_strcpy.c in /home/frostiz/CPool_Day06
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Oct 10 08:58:40 2016 thibaut trouve
** Last update Sun Jan 22 19:10:26 2017 thibaut trouve
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
