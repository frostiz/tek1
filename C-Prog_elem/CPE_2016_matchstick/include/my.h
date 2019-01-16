/*
** my.h for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:19:03 2017 
** Last update Sun Feb 26 14:55:08 2017 
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_map_info
{
  int	line_size;
  int	nb_space;
  int	nb_stick;
}		t_map;

typedef struct	s_map_qinfo
{
  int	init_nbline;
  int	actual_nbline;
  int	del_max;
  char	**map;
}		t_map2;

int	my_strlen(char *str);
void	my_putchar(char c);
void	print_starline(t_map info);
void	my_putstr(char *str);
char	*my_strcat(char *dest, char *src);
int	my_getnbr(char *str);
int	my_put_nbr(int nb);
static int	is_number(char *str);
char	*get_next_line(const int fd);
static int	count_actual_nbline(char **map);
int     next_space(char *str);
void    get_mapinfo(t_map *info, int nb_line);
void    aff_map(t_map2 data);
int     check_input_line_error(char *, char **, int);
int     check_input_nb_stick_error(char *, t_map2 info, char *);
void    del_last_elem(int line, char **map);
static void	delete_stick(char *, char *, char **);
static void	aff_ai_removed_and_del(int nb_stick, int line, t_map2 info);
int	find_longest_line(char **map);
int	find_sup_del_max(char **map, int nb_del_max);
int	is_sup_del_max(char **map, int del_max);
static int	one_line_remaining(t_map2 info);
static int	last_line_inferior_to_delmax(t_map2 info);
static int	lines_not_inferior_to_delmax(t_map2 info, int nb_stick, int line);
void    ai_turn(t_map2 info);
static void	aff_removed(char *line, char *nb_stick);
int	my_turn(t_map2 info);
static int	matchstick(t_map2 info);
char	**create_stickmap(int nb_line);
int	main(int argc, char **argv);

#endif /* MY_H_ */
