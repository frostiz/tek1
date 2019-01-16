/*
** my_strncmp.c for my_strncmp.c in /home/frostiz/CPool_Day06
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Oct 10 15:32:40 2016 thibaut trouve
** Last update Fri Jan 13 16:40:41 2017 thibaut trouve
*/

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i++;
    }
  if (s1[i] < s2[i])
    return (s1[i] - s2[i]);
  else
    return (s1[i] - s2[i]);
  return (0);
}
