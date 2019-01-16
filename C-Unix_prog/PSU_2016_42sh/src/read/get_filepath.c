/*
** get_filepath.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh/src/read
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 21 20:32:19 2017 Thibaut Trouvé
** Last update Sun May 21 20:38:42 2017 Thibaut Trouvé
*/

#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "read.h"

int		is_dir(char *path)
{
  struct stat	file;

  if (stat(path, &file) == -1)
    {
      return (0);
    }
  if ((file.st_mode & S_IFMT) == S_IFDIR)
    {
      return (1);
    }
  return (0);
}

char	*get_last_slash(char *tmp)
{
  int	i;
  int	idx;

  idx = 0;
  i = 0;
  while (tmp[i] != '\0')
    {
      if (tmp[i] == '/')
	idx = i;
      i++;
    }
  if (idx != 0)
    idx++;
  return (&tmp[idx]);
}

int	get_idx(char **file, char *tmp)
{
  int	i;
  int	idx;
  int	count;
  char	*path;

  idx = 0;
  i = 0;
  count = 0;
  path = get_last_slash(tmp);
  while (file[i] != NULL)
    {
      if (strncmp(path, file[i], (int)strlen(path)) == 0)
	{
	  idx = i;
	  count++;
	}
      i++;
    }
  if (count == 1)
    return (idx);
  return (-1);
}

int	no_match(char **file, char **str, t_autocomplete *string, int *idx)
{
  if (string->word[0] == '\0')
    {
      print_file(file, *str, string->path);
      return (1);
    }
  *idx = get_idx(file, string->word);
  if (*idx == -1)
    {
      print_file(file, *str, string->path);
      return (1);
    }
  return (0);
}
