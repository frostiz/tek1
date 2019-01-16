/*
** n4s.h for n4s.h in /home/roye_v/delivery/CPE_2016_n4s
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Jun  2 14:56:36 2017 Vincent Roye
** Last update Sun Jun  4 20:36:51 2017 Victor Dubret
*/

#ifndef	N4S_H_
# define N4S_H_

typedef struct	s_wordtab
{
  int		idx;
  int		col;
  int		line;
}		t_wordtab;

int		my_strlen(char *);
char		**my_str_to_wordtab(char *, char);
char		**move_forward(char **);
int		move_backwards();
char		*launch_command(char *);
int		turn(char **);
int		check_end(char *);
int		check_ko(char *);
int		track_cleared(char *);
int		is_zero(char **);

#endif /* !N4S_H_ */
