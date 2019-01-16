/*
** get_file.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 21 16:30:02 2017 Thibaut Trouvé
** Last update Sun May 21 22:37:11 2017 Thibaut Trouvé
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<dirent.h>
#include	"read.h"

char		**get_name(DIR *directory)
{
  struct dirent	*s_dir;
  char		**file;
  int		i;

  file = malloc(sizeof(char *));
  if (file == NULL)
    return (NULL);
  file[0] = NULL;
  s_dir = readdir(directory);
  i = 0;
  while (s_dir != NULL)
    {
      file = realloc_tab(file, s_dir->d_name);
      if (file == NULL)
	return (NULL);
      s_dir = readdir(directory);
      i++;
    }
  file[i] = NULL;
  return (file);
}

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  char	c;

  a = 0;
  b = (int)strlen(str) - 1;
  while (a < b)
    {
      c = str[a];
      str[a] = str[b];
      str[b] = c;
      a++;
      b--;
    }
  return (str);
}

char		*get_filepath(char *path, t_autocomplete *string)
{
  int		i;
  char		*tmp;

  i = (int)strlen(string->before) - 1;
  while (i > 0 && (string->before[i] == ' ' || string->before[i] == '\t'))
    i--;
  while (i > 0 && (string->before[i] != ' ' && string->before[i] != '\t'))
    i--;
  if (i > 0 && (string->before[i] == ' ' || string->before[i] == '\t'))
    i++;
  tmp = malloc(sizeof(char) * strlen(string->before) + 1);
  if (tmp == NULL)
    return (NULL);
  if (i >= 0 && string->before[strlen(string->before) - 1] != ' ' &&
      string->before[strlen(string->before) - 1] != '\t')
    strcpy(tmp, &string->before[i]);
  else
    {
      free(tmp);
      return (path);
    }
  return (tmp);
}

char		**get_file(t_autocomplete *string)
{
  DIR		*directory;
  char		**file;
  char		*path;

  path = "./";
  path = get_filepath(path, string);
  if (path == NULL)
    return (NULL);
  string->path = strdup(path);
  if (string->path == NULL)
    return (NULL);
  directory = opendir(path);
  if (directory == NULL)
    return (NULL);
  file = get_name(directory);
  if (file == NULL)
    return (NULL);
  closedir(directory);
  return (file);
}
