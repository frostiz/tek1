/*
** my_strcat.c for Pool 07 in /home/H3r3zy/rendu/CPool_Day07
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Tue Oct 11 12:44:28 2016 Lucas Sahel
** Last update Thu Mar  9 16:03:51 2017 Sahel
*/

char	*strcat_(char *dest, char *src)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = 0;
  while (dest && *dest && dest[dest_len] != '\0')
    dest_len++;
  while (src && src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
