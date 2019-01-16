/*
** my_strcpy.c for my_strcpy.c in /home/roye_v/delivery/CPool_Day06
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Oct 10 09:23:57 2016 Vincent Roye
** Last update Thu Mar 16 14:33:26 2017 Vincent Roye
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
