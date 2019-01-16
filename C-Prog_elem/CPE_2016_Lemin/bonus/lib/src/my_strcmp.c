/*
** my_strcmp.c for my_strcmp.c in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 17:51:18 2017 Vincent Roye
** Last update Sun Apr  9 18:01:15 2017 Vincent Roye
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
    i++;
  return (s1[i] - s2[i]);
}
