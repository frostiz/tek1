/*
** my.h for Navy in /home/thibaut/Repository/PSU_2016_navy
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Feb  3 14:36:59 2017 
** Last update Sun Feb 19 18:45:28 2017 
*/

#ifndef MY_H_
# define MY_H_
# define NOT_FINISH 3

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr_calc(int nb, int rest_nb);
int	my_put_nbr(int nb);
int	is_number(char *str);
char	*my_revstr(char *str);
int	my_getnbr(char *str);
void	sign_handler(int sig, siginfo_t *info, void *context);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *str);
char	**get_map();
void	aff_map(char **tab);
void	show_map(char **tab, char **enemy_tab);
char	**file_to_wordtab(int fd);
int	invalid_character(char **map);
int	nb_boat(char **map);
void	swap_char(char *a, char *b);
void	count_separator(char **map, int i, int *j, int *separator);
int	check_separators(char **map);
int	check_lenght(int lenght[4][2]);
int	check_boats_lenght(char **map);
int	check_boat_coords(char **map);
int	check_lenght_coherence(char **map);
char	**get_coords(char **map);
int	check_cross_boat(char **map);
int	is_valid_coord(char **map);
int	check_error(char **map);
void	count_k(int *k, int *j);
char	**stock_map(char **file);
char	**get_my_map(int fd);
int	print_hit_status(char **my_positions);
int	count_x(char **positions, int *nb_hit);
int	check_end(char **my_positions, char **enemy_positions, int opt);
int	game_two(char **my_positions, char **enemy_positions, char **argv);
int	player_two(char **argv);
int	check_input_validity(char *input);
int	send_signals(char *input, int pid);
void	replace_map_coord(char *input, char **enemy_positions);
int	wait_attack_position(char **enemy_positions);
int	wait_ennemy_attack_positions();
int	game_one(char **my_positions, char **enemy_positions);
int	player_one(int fd);
int	battleship(int argc, char **argv);
int	main(int argc, char **argv);

#endif /* MY_H_ */
