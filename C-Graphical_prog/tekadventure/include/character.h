/*
** character.h for character.h in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue May 23 18:11:12 2017 Vincent Roye
** Last update Sun May 28 20:21:02 2017 Vincent Roye
*/

#ifndef CHARACTER_H_
# define CHARACTER_H_

# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

typedef struct		s_right_walk
{
  sfSprite		*(sprite)[9];
  sfTexture		*(texture)[9];
}			t_right_walk;

typedef struct		s_left_walk
{
  sfSprite		*(sprite)[9];
  sfTexture		*(texture)[9];
}			t_left_walk;

typedef struct		s_up_walk
{
  sfSprite		*(sprite)[9];
  sfTexture		*(texture)[9];
}			t_up_walk;

typedef struct		s_down_walk
{
  sfSprite		*(sprite)[9];
  sfTexture		*(texture)[9];
}			t_down_walk;

typedef struct		s_left_sword
{
  sfSprite		*(sprite)[6];
  sfTexture		*(texture)[6];
}			t_left_sword;

typedef struct		s_right_sword
{
  sfSprite		*(sprite)[6];
  sfTexture		*(texture)[6];
}			t_right_sword;

typedef struct		s_walk_boss
{
  sfSprite		*(sprite)[9];
  sfTexture		*(texture)[9];
}			t_walk_boss;

typedef struct		s_wait_boss
{
  sfSprite		*(sprite)[7];
  sfTexture		*(texture)[7];
}			t_wait_boss;

typedef struct		s_attack_boss
{
  sfSprite		*(sprite)[6];
  sfTexture		*(texture)[6];
}			t_attack_boss;

typedef struct		s_boss_death
{
  sfSprite		*(sprite)[6];
  sfTexture		*(texture)[6];
}			t_boss_death;

typedef struct		s_character
{
  t_right_walk		right_walk;
  t_left_walk		left_walk;
  t_up_walk		up_walk;
  t_down_walk		down_walk;
  t_left_sword		left_sword;
  t_right_sword		right_sword;
  t_wait_boss		wait_boss;
  t_walk_boss		walk_boss;
  t_attack_boss		attack_boss;
  t_boss_death		boss_death;
  int			last_pos;
}			t_character;

typedef struct		s_move_player
{
  sfVector2f		coord;
  int			max;
  int			tmp;
  int			col;
}			t_move_player;

typedef struct		s_put_line
{
  sfVector2i		coord;
  sfVector2i		to;
  sfVector2f		tmp;
  int			move_click;
  int			i;
}			t_put_line;

int	init_sword_left(t_character *);
int	init_sword_right(t_character *);
int	init_up_walk(t_character *);
int	init_down_walk(t_character *);
int	init_right_walk(t_character *);
int	init_left_walk(t_character *);
int	init_character(t_character *);
int	init_wait_boss(t_character *);
int	init_walk_boss(t_character *);
int	init_attack_boss(t_character *);
int	init_boss_death(t_character *);

#endif /* !CHARACTER_H_ */
