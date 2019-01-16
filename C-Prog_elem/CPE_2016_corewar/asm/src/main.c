/*
** main.c for main.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar/ASM
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 13:21:10 2017 Vincent Roye
** Last update Sun Apr  2 09:15:19 2017 dubret_v
*/

#include <stdio.h>
#include "my.h"
#include "asm.h"

static void	display_help(char *program_name)
{
  my_printf("USAGE\n");
  my_printf("\t%s file_name[.s]\n\n", program_name);
  my_printf("DESCRIPTION\n");
  my_printf("\tfile_name\tfile in assembly language to be");
  my_printf(" converted into file_name.cor, an\n\t\t\texecutable in the");
  my_printf(" Virtual Machine.\n");
}

int	need_help(int ac, char **argv)
{
  int	i;

  i = 0;
  if (ac <= 1)
    {
      display_help(argv[0]);
      return (1);
    }
  while (argv[i] != NULL)
    {
      if (my_strcmp(argv[i], "-h") == 0)
	{
	  display_help(argv[0]);
	  return (1);
	}
      i++;
    }
  return (0);
}

int	main(int ac, char **argv)
{
  int	i;

  i = 1;
  if (need_help(ac, argv) == 1)
    return (0);
  if (check_files_extension(argv) == 1)
    return (84);
  while (argv[i] != NULL)
    {
      if (my_asm(argv[i]) == 1)
	return (84);
      i++;
    }
  return (0);
}
