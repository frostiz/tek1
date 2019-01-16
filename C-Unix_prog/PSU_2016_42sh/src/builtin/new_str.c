/*
** new_str.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 12:58:53 2017 bastien bedu
** Last update Sun May 21 21:35:59 2017 bastien bedu
*/

#include	<stdlib.h>
#include	<string.h>
#include	"env.h"
#include	"mysh.h"

char		*my_strdup_to(char *str, int to)
{
  char		*new;
  int		i;

  new = malloc(sizeof(char) * (to + 1));
  if (new == NULL)
    exit(84);
  i = 0;
  while (str != NULL && i < to && str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

int		malloc_truelen(char *str, char **result)
{
  int		i;
  int		j;
  int		sum;

  i = 0;
  sum = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] == '$')
	{
	  j = i;
	  while (is_char_alphanum(str[j]) == 1)
	    j++;
	  sum += i - j;
	}
      i++;
    }
  sum += i;
  i = 0;
  while (result != NULL && result[i] != NULL)
    {
      sum += strlen(result[i]);
      i++;
    }
  return (sum);
}

char		**malloc_it(char *str)
{
  char		**result;
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] == '$')
	count++;
      i++;
    }
  result = malloc(sizeof(char *) * (count + 1));
  if (result == NULL)
    exit(84);
  result[count] = NULL;
  return (result);
}

char		*cat_all(char *str, char **result)
{
  char		*new;
  int		i;
  int		j;
  int		count;

  i = 0;
  j = 0;
  count = 0;
  new = malloc(sizeof(char) * (malloc_truelen(str, result) + 1));
  if (new == NULL)
    exit(84);
  while (str != NULL && str[i] != '\0')
    if (str[i] == '$')
      {
	j += add_var(result[count], &new[j], str, &i);
	count++;
      }
    else
      {
	new[j] = str[i];
	j++;
	i++;
      }
  new[j] = '\0';
  return (new);
}

char		*get_mod_str(char **env, char *str)
{
  char		**result;
  char		*var;
  int		i;
  int		nb_var;

  i = 0;
  nb_var = 0;
  result = malloc_it(str);
  while (str != NULL && str[i] != '\0')
    if (str[i] == '$')
      {
	i++;
	if (get_env_of(&str[i], nb_var, env, result) == 0)
	  {
	    free(str);
	    return (NULL);
	  }
	nb_var++;
      }
    else
      i++;
  var = cat_all(str, result);
  my_free_tab(result);
  free(str);
  return (var);
}
