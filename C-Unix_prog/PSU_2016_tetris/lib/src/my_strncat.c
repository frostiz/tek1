/*
** my_strncat.c for Pool 07 in /home/H3r3zy/rendu/CPool_Day07
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Tue Oct 11 13:10:01 2016 Lucas Sahel
** Last update Fri Feb 17 08:59:20 2017 Sahel
*/

char	*strncat_(char *dest, char *src, int nb)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = 0;
  while (dest[dest_len] != '\0')
    dest_len++;
  while (i < nb && src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
