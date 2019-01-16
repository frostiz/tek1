/*
** check_file_extension.c for corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 00:50:57 2017 
** Last update Wed Mar 29 04:52:54 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int	check_files_extension(char **argv)
{
  int	i;

  i = 0;
  while (argv[i] != NULL)
    {
      if (i > 0)
	{
	  if (argv[i][my_strlen(argv[i]) - 2] != '.' ||
	      argv[i][my_strlen(argv[i]) - 1] != 's')
	    {
	      my_printf("Invalid extension for \"%s\"\n", argv[i]);
	      return (1);
	    }
	}
      i++;
    }
  return (0);
}
