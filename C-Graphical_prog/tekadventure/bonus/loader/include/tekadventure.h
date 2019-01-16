/*
** tekadventure.h for tekadventure.h in /home/roye_v/delivery/tekadventure/include
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 21 10:23:32 2017 Vincent Roye
** Last update Sun May 28 18:34:52 2017 thibaut trouve
*/

#ifndef TEKADVENTURE_H_
# define TEKADVENTURE_H_
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 900

typedef struct	s_my_framebuffer
{
  sfUint8*	pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct	s_diag
{
  int		x_inclin;
  int		y_inclin;
  int		cumul;
  int		dx;
  int		dy;
  int		i;
  int		x;
  int		y;
}		t_diag;

typedef struct		s_window
{
  t_my_framebuffer*	framebuffer;
  sfRenderWindow*	window;
  sfTexture		*texture;
  sfEvent		event;
  sfSprite*		sprite;
}			t_window;

typedef struct		s_loader
{
  int			*width;
  int			*height;
  char			*c_width;
  char			*c_height;
  int			*file;
  int			file_size;
  int			*img_size;
  int			*img;
  int			fd;
}			t_loader;

int			*load_img(char *);
char			*my_strcat(char *, char *);
char			*my_base(int, int);
int			get_file_size(char *);
int			*get_int_tab(int *, int);
int			*rev_int(int *);
int			hex_to_int(char *);
int			my_strlen(char *);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			my_put_pixel2(t_my_framebuffer *, sfVector2i, sfColor,
				      int *);
void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
void			my_draw_line2(t_my_framebuffer *, sfVector2i,
				      sfVector2i, sfColor);
void			my_draw_square(t_my_framebuffer *, sfVector2i,
				       sfVector2i, sfColor);
sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);

#endif /* !TEKADVENTURE_H */
