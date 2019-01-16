/*
** open_files_redir_failure.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 04:20:10 2017 Thibaut Trouvé
** Last update Wed May  3 04:32:11 2017 Thibaut Trouvé
*/

#include "main.h"
#include "my.h"

char	*get_file(char **args, char *op)
{
  int	i;

  i = 0;
  while (args[i] != NULL)
    {
      if (my_strcmp(args[i], op) == 0)
	return (args[i + 1]);
      i++;
    }
  return (NULL);
}

int	open_failure(char *file, t_tab **data)
{
  my_putstr(file);
  (*data)->exit_value = 1;
  if (is_dir(file) == 1)
    {
      my_putstr(": Is a directory.\n");
      return (-1);
    }
  my_putstr(": No such file or directory.\n");
  return (-1);
}
