/*
** path.c for path.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:16:28 2017 thibaut trouve
** Last update Sun Jan 22 23:37:47 2017 thibaut trouve
*/

#include "my.h"

char	*find_good_path(int pos_path, char *tmp_path, char **tab, char **env)
{
  int   i;
  int   j;

  i = 5;
  j = 0;
  while (env[pos_path][i] != '\0')
    {
      tmp_path[j] = env[pos_path][i];
      i++;
      j++;
      if (env[pos_path][i] == ':')
	{
	  tmp_path[j] = '/';
	  j++;
	  tmp_path[j] = '\0';
	  my_strcat(tmp_path, tab[0]);
	  if (access(tmp_path, F_OK) == 0)
	    return (tmp_path);
	  j = 0;
	  i++;
	}
    }
  return (NULL);
}

char	*test_paths(char **tab, char **my_env)
{
  int           pos_path;
  char          *tmp_path;

  if (tab[0] == NULL || tab == NULL || my_env == NULL || tab[0][0] == '\0')
    return (NULL);
  if (is_slash(tab[0]) == 1)
    {
      if (access(tab[0], X_OK) == 0)
	return (tab[0]);
      return (NULL);
    }
  if ((pos_path = find_path(my_env)) == -1)
    return (NULL);
  if ((tmp_path = malloc(sizeof(char) * (my_strlen(my_env[pos_path])
					 + 2))) == NULL)
    return (NULL);
  return (find_good_path(pos_path, tmp_path, tab, my_env));
}

int	is_slash(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

void	init_struct(t_count *count)
{
  count->i = 0;
  count->j = 0;
  count->k = 0;
}
