/*
** tetrimino.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Wed Mar  8 21:55:50 2017 Sahel
** Last update Sun Mar 19 20:53:01 2017 
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "main.h"
#include "basic.h"
#include "get_next_line.h"

static char	**take_tetrimino(int fd, int size, int width, int height)
{
  char		**tetrimino;
  char		*buf;
  int		line;
  int		mcol;

  line = 0;
  mcol = 0;
  tetrimino = malloc_square_tab(size);
  while ((buf = getnextline_(fd)))
    {
      without_last_char(buf, ' ');
      if (line_starspace(buf) || strlen_(buf) > width ||
	  ((*buf) && line >= height) || line >= height)
	return (NULL);
      if (mcol < strlen_(buf))
	mcol = strlen_(buf);
      move_str(tetrimino[line], buf);
      line++;
    }
  if (line != height || mcol != width)
    return (NULL);
  tetrimino[line] = NULL;
  return (tetrimino);
}

static void	new_tetrimino_db(t_datamap *game, t_tetriminos *tetri)
{
  if (game->debug == 1)
    {
      putstr_("Size ", 1);
      putnbr_(tetri->width);
      putstr_("*", 1);
      putnbr_(tetri->height);
      putstr_(" : Color ", 1);
      putnbr_(tetri->color);
      putstr_(" :\n", 1);
      puttab_(tetri->tetriminos, 1);
    }
}

int	new_tetrimino(t_datamap *game, char *path)
{
  struct stat	st;
  int		fd;
  char		**config;
  t_tetriminos	*tetri;

  path = concat("tetriminos/", path);
  fd = open(path, O_RDONLY);
  if (fd < 0 || lstat(path, &st) == -1 || S_ISDIR(st.st_mode) ||
      !(tetri = malloc(sizeof(t_tetriminos))) ||
      !(config = parse_(getnextline_(fd), ' ')) || tablen_(config) != 3)
    return (close_(fd, 84));
  tetri->width = getnbr_(config[0]);
  tetri->height = getnbr_(config[1]);
  tetri->color = getnbr_(config[2]);
  if (tetri->color < 0 || tetri->color > 7 ||
      !(tetri->tetriminos = take_tetrimino(fd, (tetri->width > tetri->height) ?
					   (tetri->width) : (tetri->height),
					   tetri->width, tetri->height)))
    return (close_(fd, 84));
  stock_in_list(game, tetri);
  new_tetrimino_db(game, tetri);
  return (close_(fd, 0));
}

static int	aff_nb_tetriminos(t_datamap *game)
{
  struct dirent	**dirent;
  int		nb_file;
  int		file_i;
  int		nb;

  nb = 0;
  nb_file = scandir("tetriminos", &dirent, NULL, alphasort);
  file_i = 0;
  while (file_i < nb_file)
    {
      if (match(dirent[file_i]->d_name, "*.tetrimino"))
	{
	  nb++;
	}
      file_i++;
    }
  if (game->debug == 1)
    {
      putstr_("Tetriminos : ", 1);
      putnbr_(nb);
      putstr_("\n", 1);
    }
  if (nb == 0)
    return (84);
  return (0);
}

int		get_tetrimino(t_datamap *game)
{
  struct stat	st;
  struct dirent	**dirent;
  int		nb_file;
  int		file_i;

  if (lstat("tetriminos/", &st) == -1 || S_ISDIR(st.st_mode) == 0)
    return (84);
  nb_file = scandir("tetriminos", &dirent, NULL, alphasort);
  if (nb_file <= -1 || aff_nb_tetriminos(game) == 84)
    return (84);
  file_i = 0;
  while (file_i < nb_file)
    {
      if (match(dirent[file_i]->d_name, "*.tetrimino"))
	call_new_tetri(game, dirent[file_i]->d_name);
      file_i++;
    }
  list_circu(game);
  return (0);
}
