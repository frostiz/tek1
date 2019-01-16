/*
** my.h for my.h in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Dec 15 21:50:45 2016 thibaut trouve
** Last update Mon Dec 19 15:55:40 2016 thibaut trouve
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef struct s_count {
  int	i;
  int	j;
  int	k;
} t_count;

typedef struct s_maps_info {
  char	**map;
  char	**map_o;
  int	col_max;
  int	row_max;
} t_maps;

int	my_strlen(char *);
int	get_col_and_raw_max(int *, char **);
char    **stock_map(char **, int, int);
int	*find_p(char **);
void	swap(char *, char *);
void	move_right(char **, int *, char **);
void	move_left(char **, int *, char **);
void	move_up(char **, int *, char **);
void	move_down(char **, int *, char **);
int	count_o(char **);
int	check_win(char **, char **);
int	check_nb_o(char **);
int	check_lose(char **);
void	aff_map(char **, int, int);
void	interpret_ch(int, t_maps *, int *);
void	make_window(void);
void	my_putstr(char *);
void	check_around(char **, int, int, int*);
void    end_map_line(t_count *, char **, int);
void	stock_position(int *, int, int, int *);
void	stock_position_restart(t_maps, int, int, int *);
int	free_memory(char **, int);
int	check_map(char **);

#endif
