/*
** init_texture_s.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 18:22:26 2017 Victor Dubret
** Last update Sun May 28 19:06:54 2017 Victor Dubret
*/

#include		"tekadventure.h"

t_inventory		init_textures_s(t_inventory inventory, int *check)
{
  char		*inventory_character[6];
  int		i;

  i = 0;
  inventory_character[0] = "pictures/inventory/red_sword1.png";
  inventory_character[1] = "pictures/inventory/red_sword2.png";
  inventory_character[2] = "pictures/inventory/red_sword3.png";
  inventory_character[3] = "pictures/inventory/red_sword4.png";
  inventory_character[4] = "pictures/inventory/red_sword5.png";
  inventory_character[5] = "pictures/inventory/red_sword6.png";
  while (i < 6)
    {
      inventory.texture_character_s[i] =
	sfTexture_createFromFile(inventory_character[i], NULL);
      if (!inventory.texture_character_s[i])
	{
	  *check = 1;
	  return (inventory);
	}
      i++;
    }
  return (inventory);
}
