/*
** tunnel.h for tunnel.h in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 14:40:49 2017 Vincent Roye
** Last update Sun Apr 30 15:21:45 2017 Vincent Roye
*/

#ifndef TUNNEL_H_
# define TUNNEL_H_

typedef struct	s_stock
{
  char		**tunnel;
  char		**tmp;
  int		i;
}		t_stock;

typedef struct		s_idx_tunnel
{
  int			space;
  int			hashtag;
  int			dash;
  int			line;
  int			i;
}			t_idx_tunnel;

typedef struct		s_empty
{
  char			**tmp;
  int			line;
  int			line2;
  int			i;
  int			j;
}			t_empty;

char	**delete_emptyline(char **);

#endif /* TUNNEL_H_ */
