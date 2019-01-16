/*
** main.h for main.h in /home/thibaut/Repository/CPE_2016_Lemin
**
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Thu Apr 13 18:04:41 2017 Thibaut Trouvé
** Last update Sun Apr 30 23:26:33 2017 Vincent Roye
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define START 1
# define END 2
# include <SFML/Graphics.h>

typedef struct		s_index
{
  int			i;
  int			line;
  int			j;
  int			max;
}			t_index;

typedef struct		s_dataroom
{
  char			*name;
  int			x;
  int			y;
  int			pos;
}			t_dataroom;

typedef struct		s_ever_passed
{
  struct s_ever_passed	*next;
  char			*room_name;
  char			**is_passed;
}			t_ever_passed;

typedef struct		s_path
{
  struct s_path		*next;
  char			**path;
  int			over;
}			t_path;

typedef struct		s_rooms
{
  t_dataroom		*data;
  char			**tunnel;
  struct s_rooms	*next;
}			t_rooms;

typedef struct		s_tunnel
{
  struct s_map		**link_address;
  char			**link_name;
}			t_tunnel;

typedef struct		s_map
{
  t_dataroom		data;
  t_tunnel		link;
}			t_map;

typedef struct		s_name_path
{
  char			**path;
  char			*name;
}			t_name_path;

typedef struct		s_dup
{
  struct s_dup		*next;
  char			**duplicate;
}			t_dup;

typedef struct		s_wordtab
{
  int			i;
  int			j;
  int			k;
  char			**tab;
}			t_wordtab;

char		**copy_file();
char		**my_str_to_wordtab(char *);
char		**my_tunnel_to_wordtab(char *);
char		**stock_tunnel(char **, int, char *, t_rooms *);
char		**stock_tunnel2(char **, int, char *, int);
char		**epure_stock(char **);
char		**my_tabdup(char **);
void		print_tab(char **);
void		free_tab(char **);
void		display_tunnels(t_rooms *);
int		display_rooms(t_rooms *);
int		get_idx_error(char **, int, t_rooms *);
int		check_room(t_rooms *, char *, int);
int		check_coord(t_rooms *, int, int, int);
void		fill_that(char **, char *, char *);
int		array_len(char **);
int		is_passed(char **, char *);
int		max_str_size(char **);
int		get_idx_tunnel(char **);
int		count_room(char **, int, char **);
int		check_double_link(char **, char *, int);
int		display_graph(t_map *, char **);
int		get_nb_fourmi(char **);
int		check_errors(t_rooms *, int);
int		recursive_functions(t_map *, int);
int		check_invalid_map(char **, int);
int		check_room_error(t_rooms *);
int		check_end_tunnel(t_rooms *);
int		path_len(t_path *);
int		check_end_start(t_rooms *, int *, int *);
t_ever_passed	*init_ever_passed(t_ever_passed *, t_map *, t_name_path);
t_ever_passed	*init_passed(t_ever_passed *, char **, char *, char *);
t_path		*search_path(t_map *, t_name_path, t_path *, t_ever_passed *);
t_path		*go_through_graph(t_map *, t_ever_passed *,
				  t_path *, t_name_path);
t_dataroom	*get_data(char **, int *);
t_map		*mapping(t_rooms *);
t_rooms		*fill_rooms(t_dataroom *, t_rooms *, char **, int);
t_rooms		*add_links(t_rooms *, t_dataroom *, char **, int);
t_rooms		*parse_tunnels(t_rooms *, char **, int *);
t_rooms		*parse_rooms(t_rooms *, char **, int *);
int		parse_nb_ants(char **, int *);
int		display_rooms(t_rooms *);
int		check_room_error(t_rooms *);
t_map		**prepare_rooms(t_rooms *);
t_map		**stock_struct_address(t_map **);
t_dup		*add_duplicate(t_dup *, char *, char *);
int		print_map(t_rooms *);
int		fill_datamap(t_map **, t_rooms *);
int		tunnel_counter(char **);
int		is_duplicate(char *, char *, t_dup *);

#endif /* !LEMIN_H_ */
