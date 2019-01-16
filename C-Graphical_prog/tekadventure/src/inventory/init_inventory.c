/*
** init_inventory.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sat May 27 15:27:42 2017 Victor Dubret
** Last update Mon May 29 09:36:43 2017 Victor Dubret
*/

#include		"tekadventure.h"

static t_inventory	init_objects(t_inventory inventory, int *check, int i)
{
  char		*inventory_pictures[9];

  inventory_pictures[0] = "pictures/inventory/inventory.png";
  inventory_pictures[1] = "pictures/inventory/Gold_key.png";
  inventory_pictures[2] = "pictures/inventory/Sword.png";
  inventory_pictures[3] = "pictures/inventory/generator.png";
  inventory_pictures[4] = "pictures/inventory/master.png";
  inventory_pictures[5] = "pictures/inventory/turbine-1.png";
  inventory_pictures[6] = "pictures/inventory/turbine-2.png";
  inventory_pictures[7] = "pictures/inventory/wings-1.png";
  inventory_pictures[8] = "pictures/inventory/wings-2.png";
  while (i < 9)
    {
      inventory.textures[i] =
	sfTexture_createFromFile(inventory_pictures[i], NULL);
      if (!inventory.textures[i])
	{
	  *check = 1;
	  return (inventory);
	}
      i++;
    }
  return (inventory);
}

static	t_inventory	init_character_inventory(t_inventory inventory,
						 int *check)
{
  char		*inventory_character[9];
  int		i;

  i = 0;
  inventory_character[0] = "pictures/inventory/walk_inventory1.jpg";
  inventory_character[1] = "pictures/inventory/walk_inventory2.jpg";
  inventory_character[2] = "pictures/inventory/walk_inventory3.jpg";
  inventory_character[3] = "pictures/inventory/walk_inventory4.jpg";
  inventory_character[4] = "pictures/inventory/walk_inventory5.jpg";
  inventory_character[5] = "pictures/inventory/walk_inventory6.jpg";
  inventory_character[6] = "pictures/inventory/walk_inventory7.jpg";
  inventory_character[7] = "pictures/inventory/walk_inventory8.jpg";
  inventory_character[8] = "pictures/inventory/walk_inventory9.jpg";
  while (i < 9)
    {
      inventory.texture_character[i] =
	sfTexture_createFromFile(inventory_character[i], NULL);
      if (!inventory.texture_character[i])
	{
	  *check = 1;
	  return (inventory);
	}
      i++;
    }
  return (inventory);
}

static void		init_set_texture(t_inventory inventory)
{
  int			i;

  i = 0;
  while (i < 9)
    {
      sfSprite_setTexture(inventory.sprites[i],
			  inventory.textures[i], sfTrue);
      i++;
    }
  i = 0;
  while (i < 9)
    {
      sfSprite_setTexture(inventory.sprites_character[i],
			  inventory.texture_character[i], sfTrue);
      i++;
    }
  i = 0;
  while (i < 6)
    {
      sfSprite_setTexture(inventory.sprites_character_s[i],
			  inventory.texture_character_s[i], sfTrue);
      i++;
    }
}

t_inventory		init_sprites_inventory(t_inventory inventory)
{
  int			i;

  i = 0;
  while (i < 9)
    {
      inventory.sprites[i] = sfSprite_create();
      i++;
    }
  i = 0;
  while (i < 9)
    {
      inventory.sprites_character[i] = sfSprite_create();
      i++;
    }
  i = 0;
  while (i < 6)
    {
      inventory.sprites_character_s[i] = sfSprite_create();
      i++;
    }
  return (inventory);
}

t_inventory		init_inventory(int *check)
{
  t_inventory	inventory;
  int		i;

  i = 0;
  inventory.is_open = 0;
  inventory.gold_key = 0;
  inventory.sword = 0;
  while (i < 6)
    {
      inventory.piece_ship[i] = 0;
      i++;
    }
  inventory = init_sprites_inventory(inventory);
  inventory = init_objects(inventory, check, 0);
  if (*check == 1)
    return (inventory);
  inventory = init_character_inventory(inventory, check);
  if (*check == 1)
    return (inventory);
  inventory = init_textures_s(inventory, check);
  if (*check == 1)
    return (inventory);
  init_set_texture(inventory);
  return (inventory);
}
