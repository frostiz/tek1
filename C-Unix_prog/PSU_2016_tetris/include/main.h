/*
** main.h for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 15:11:22 2017 Sahel
** Last update Sun Mar 19 23:17:08 2017 
*/

#ifndef MAIN_H_
# define MAIN_H_

/*
** /!\ DON'T USE % IN MACRO CHAR OR YOU DIE
**     AND 1 AND ONLY 1 CHARACTERE IS EXPECTED
**     NOT LESS NOT MORE OR DIE
**     AND NOT SPECIAL CHAR LIKE €
*/

# define CHAR "@"

typedef struct		s_tetriminos
{
  struct s_tetriminos	*next;
  struct s_tetriminos	*previous;
  int			width;
  int			height;
  int			color;
  char			**tetriminos;
}			t_tetriminos;

typedef struct	s_flag
{
  int		help;
  int		debug;
  int		without;
  int		kt;
  int		kl;
  int		kr;
  int		kp;
  int		kd;
  int		level;
  int		mapsize;
  int		kq;
  int		validity;
}		t_flag;

typedef struct	s_keys
{
  char		*turn;
  char		*left;
  char		*right;
  char		*drop;
  char		*pause;
  char		*quit;
}		t_keys;

typedef struct	s_stats
{
  int		score;
  int		high_score;
  char		**next_tetrimino;
  long long int	chrono;
  long int	cps;
  int		line_deleted;
}		t_stats;

typedef struct	s_datamap
{
  int		level;
  int		map_size[2];
  t_keys	key;
  int		without_next;
  int		debug;
  int		help;
  int		pause;
  long long int	time;
  long long int	timeout;
  long int	cl;
  int		random;
  t_tetriminos	*tetriminos;
  char		coord[2];
  char		**map_only_one;
  char		**map;
  t_stats	stat;
}		t_datamap;

t_datamap	*init_game(char **);
t_flag		init_flag(t_flag);
t_flag		check_flags_validity(char **);
char		**parse_(char *, char);
char		**create_map(int *);
char		**get_tetriminos_coord(t_datamap *, char **);
char		**get_sequences(t_keys);
char		**malloc_square_tab(int);
char		*getenv_(char **, char *);
char		*without_before_(char *, char);
char		*concat(char *, char *);
char		*cat_key_pressed(char **);
char		*realloc_(char *, int);
char		*take_name(char *);
int		puterror_(char *, int);
int		get_tetrimino(t_datamap *);
int		check_flags(int, char **, t_datamap *);
int		flags_level(char **, int *, t_datamap *);
int		flags_left(char **, int *, t_datamap *);
int		flags_right(char **, int *, t_datamap *);
int		flags_drop(char **, int *, t_datamap *);
int		flags_pause(char **, int *, t_datamap *);
int		flags_quit(char **, int *, t_datamap *);
int		flags_turn(char **, int *, t_datamap *);
int		flags_mapsize(char **, int *, t_datamap *);
int		flags_without(char **, int *, t_datamap *);
int		flags_debug(char **, int *, t_datamap *);
int		help(char *, int);
int		mode(int, int);
int		colision_bas(t_datamap *);
int		game_loop(t_datamap *, char **, char **);
int		interpret_sequence(int, t_datamap *);
int		find_key_pressed(char **, char *);
int		check_sequence_validity(char *, char **);
int		prepare_game(char **);
int		start_game(t_datamap *);
int		need_help(char **);
int		debug(t_datamap *);
int		sp_len_(char *, char);
int		nb_stars(char **);
int		drop_tetrimino(t_datamap *);
int		colision(t_datamap *, char **);
int		colision_right(t_datamap *);
int		colision_left(t_datamap *);
int		is_sequence(char **, char **);
int		line_starspace(char *);
int		new_tetrimino(t_datamap *, char *);
int		close_(int, int);
void		aff_interface(t_datamap *);
void		move_str(char *, char *);
void		free_tab(char **);
void		descendre(char **);
void		turn(t_datamap *);
void		move_right(t_datamap *);
void		move_left(t_datamap *);
void		put_tetri(t_datamap *);
void		fusion(char **, char **);
void		aff_map(t_datamap *);
void		aff_next_tetrimino(t_datamap);
void		take_next(t_datamap *);
void		score_line(t_datamap *);
void		without_last_char(char *, char);
void		stock_in_list(t_datamap *, t_tetriminos *);
void		list_circu(t_datamap *);
void		call_new_tetri(t_datamap *, char *);
void		aff_stats(t_datamap *);
void		interpret_exist(int, char **, char **, t_datamap *);
void		setcolor();
void		show_game(t_datamap *);
int		get_high();
int		stock_score(t_datamap *);

#endif /* !MAIN_H_ */
