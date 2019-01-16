/*
** my_strcat.c for my_strcat.c in /home/roye_v/delivery/PSU_2016_minishell1
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Jan 16 16:26:17 2017 Vincent Roye
** Last update Sun Apr  9 18:01:07 2017 Vincent Roye
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  int	dest_len;

  i = 0;
  dest_len = 0;
  while (dest[dest_len] != '\0')
    dest_len++;
  j = dest_len;
  while (src[i] != '\0')
    {
      dest[i + j] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
