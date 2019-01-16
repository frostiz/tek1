/*
** my_event.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 20:08:23 2017 Victor Dubret
** Last update Sun May 28 21:21:42 2017 Victor Dubret
*/

#include	"tekadventure.h"

t_loop		my_event(t_game *game, t_loop loop)
{
  while (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue)
    game->inventory.is_open = 1;
  return (loop);
}
