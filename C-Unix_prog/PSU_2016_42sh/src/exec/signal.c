/*
** signal.c for  in /home/bastien/delivery/PSU/PSU_2016_minishell1
** 
** Made by bastien bedu
** Login   <bastien@epitech.net>
** 
** Started on  Sat Jan 21 22:36:37 2017 bastien bedu
** Last update Fri May 19 12:04:47 2017 bastien bedu
*/

#include	<sys/wait.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"exec.h"

void		add_again(char **tab)
{
  tab[23] = "";
  tab[24] = "Cputime limit exceeded";
  tab[25] = "Filesize limit exceeded";
  tab[26] = "Virtual time alarm";
  tab[27] = "Profiling time alarm";
  tab[28] = "";
  tab[29] = "Pollable envent occured";
  tab[30] = "Power failure";
  tab[31] = "Bad system call";
}

void		init_tab(char **tab, int signal)
{
  tab[1] = "Hangup";
  tab[2] = "";
  tab[3] = "Quit";
  tab[4] = "Illegal instruction";
  tab[5] = "Trace/BTP trap";
  tab[6] = "Abort";
  tab[7] = "Bus error";
  tab[8] = "Floating exception";
  tab[9] = "Killed";
  tab[10] = "User signal 1";
  tab[11] = "Segmentation fault";
  tab[12] = "User signal 2";
  tab[13] = "Broken pipe";
  tab[14] = "Alarm clock";
  tab[15] = "Terminated";
  tab[16] = "Stack limit exceeded";
  tab[17] = "";
  tab[18] = "";
  tab[19] = "Suspended (signal)";
  tab[20] = "Suspended";
  tab[21] = "Suspended (tty input)";
  tab[22] = "Suspended (tty output)";
  add_again(tab);
  my_perror(tab[signal]);
}

int		signal_handle(int status, int write)
{
  char		**tab;
  int		signal;
  int		result;

  result = status;
  if (WIFEXITED(status))
    result = WEXITSTATUS(status);
  else if (WIFSIGNALED(status) && !WCOREDUMP(status))
    result = status + 128;
  if (write == -1 && WIFSIGNALED(status))
    {
      signal = WTERMSIG(status);
      if (signal < 1 || signal == 17 || signal == 18 || signal == 23
	  || signal == 28 || signal > 31)
	return (result);
      tab = malloc(sizeof(char *) * 32);
      if (tab == NULL)
	return (1);
      init_tab(tab, signal);
      free(tab);
      if (WCOREDUMP(status))
	my_perror(" (core dumped)");
      my_perror("\n");
    }
  return (result);
}
