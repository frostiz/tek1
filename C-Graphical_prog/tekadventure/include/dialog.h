/*
** dialog.h for tekadventure in /home/frostiz/repository/tekadventure
**
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Thu May 25 12:53:34 2017 thibaut trouve
** Last update Sun May 28 05:20:37 2017 Antoine Duez
*/

#ifndef __DIALOG_H__
# define __DIALOG_H__

typedef struct		s_datatext
{
  char			*string;
  char			*font_path;
  int			size;
  sfColor		color;
}			t_datatext;

typedef struct		s_dialog
{
  sfText		*text;
  sfRectangleShape	*border;
}			t_dialog;

typedef struct		s_attribute
{
  sfVector2f		scale;
  sfVector2f		pos;
  float			angle;
}			t_attribute;

t_dialog		create_dialog(t_datatext , struct s_attribute);

#endif /* !DIALOG_H */
