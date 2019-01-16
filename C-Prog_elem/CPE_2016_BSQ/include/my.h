/*
** my.h for my.h in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Dec  8 17:03:28 2016 thibaut trouve
** Last update Sun Dec 18 17:22:13 2016 thibaut trouve
*/

#ifndef MY_H_
# define MY_H_
# define BUF_SIZE 1048576

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_count {
  int	i;
  int	j;
  int	tmp;
  int	max;
  int	posx;
  int	posy;
} t_count;

typedef struct s_stockage {
  int   nb_line;
  int   line_len;
  char  **tab;
  int   fd;
  int   i;
  char  buffer[BUF_SIZE];
  int   j;
  int   k;
} t_stock;

int	beginning_of_file(char *);
int	my_strlen(char *);
int	check_filled(char **);
int	lign_lenght(char *);
int	beginning(char **);
int	map_one_column(char **);
void	aff_loop(char **);
void	my_putchar(char);
void	replace_point(int, int, int, char **);
int	check(char **, int, int);
char	**stock(char **);
int	count_lines(char **, int *);
void	aff(int *, int *, char buff_aff[BUF_SIZE]);
void	aff_loop(char **);
void	aff_empty(char **);
int	check_square(char **, int, int, int);
int	check(char **, int , int);
int	check_empty(char **);
void	init_struct(t_count *);
void	algo(char **);
int	count_lines(char **, int *);
char	*my_strdup(char *);
int	size_one(char *);
int	map_one_column(char **);
char	**loop_stock(t_stock);
char	**stock(char **);

#endif /* !MY_H_ */
