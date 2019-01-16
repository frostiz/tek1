/*
** read.h for read.h in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri May 19 14:10:10 2017 Vincent Roye
** Last update Sun May 21 22:00:23 2017 Thibaut Trouvé
*/

#ifndef READ_H_
# define READ_H_

# define BACKLINE 10
# define CTRL_A 1
# define CTRL_D 4
# define CTRL_E 5
# define CTRL_G 7
# define CTRL_H 8
# define CTRL_L 12
# define CTRL_N 14
# define CTRL_O 15

# define DEL 127

typedef struct		s_keys
{
  char			*left;
  char			*right;
  char			*up;
  char			*down;
  char			*remove;
}			t_keys;

typedef struct		s_hist
{
  char			**hist;
  int			len;
  int			idx;
}			t_hist;

typedef struct		s_autocomplete
{
  char			*before;
  char			*after;
  char			*word;
  char			*path;
}			t_autocomplete;

typedef struct		s_read
{
  int			size;
  char			buff[10];
  char			*str;
  char			*tmp;
  int			cursor;
  int			ret;
}			t_read;

char			**realloc_tab(char **, char *);
char			*read_command(t_keys *, t_hist *);
char			*insert_char(char *, int, char);
char			**add_history(char *, t_hist *);
void			del_char(char *, int);
int			init_term(t_keys *);
int			mode(int);
void			my_putstr(char *);
char			*add_char(char *, int *, char *);
int			which_sequences(t_keys *, char *);
char			*known_sequences(int, int *, char *, t_hist *);
char			*keys_up(char *, int *, t_hist *);
char			*keys_right(char *, int *, t_hist *);
char			*keys_down(char *, int *, t_hist *);
char			*keys_left(char *, int *, t_hist *);
char			*keys_remove(char *, int *, t_hist *);
int			init_keys(t_keys *);
int			which_control_sequences(char *);
int			control_sequences(int, int *, char *);
int			control_backline(char *, int *);
int			control_a(char *, int *);
int			control_o(char *, int *);
int			control_g(char *, int *);
int			control_n(char *, int *);
int			control_e(char *, int *);
int			control_d(char *, int *);
int			control_l(char *, int *);
int			control_h(char *, int *);
int			control_del(char *, int *);
int			autocomplete(char **, int *);
int			is_dir(char *);
int			no_match(char **, char **, t_autocomplete *, int *);
void			print_file(char **, char *, char *);
char			*get_word(char *, int *);
char			*get_before_word(char *, int *);
char			*get_after_word(char *, int *);
char			**get_file();

#endif /* !READ_H_  */
