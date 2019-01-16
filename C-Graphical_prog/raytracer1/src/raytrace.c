/*
** raytrace.c for raytracer in /home/thibaut/Repository/raytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 18:32:55 2017 
** Last update Sun Mar 19 23:33:18 2017 
*/

#include "my.h"

static void	init_scene(t_scene *scene)
{
  scene->screen_size.x = WIDTH;
  scene->screen_size.y = HEIGHT;
  scene->eye_pos.x = -200;
  scene->eye_pos.y = 0;
  scene->eye_pos.z = 25;
  scene->screen_pos.x = 0;
  scene->screen_pos.y = 0;
}

static void	interpret_dist(float kplane,
			       float kform,
			       t_scene scene,
			       t_my_framebuffer *framebuffer)
{
  if (kform < 0.0 && kplane < 0.0)
    my_put_pixel(framebuffer, scene.screen_pos.x,
		 scene.screen_pos.y, sfBlack);
  else if (kform > 0.0 && kplane < 0.0)
    my_put_pixel(framebuffer, scene.screen_pos.x,
		 scene.screen_pos.y, sfRed);
  else if (kform > 0.0 && kplane > 0.0)
    {
      if (kform < kplane)
	my_put_pixel(framebuffer, scene.screen_pos.x,
		     scene.screen_pos.y, sfRed);
      else
	my_put_pixel(framebuffer, scene.screen_pos.x,
		     scene.screen_pos.y, sfBlue);
    }
  else if (kform < 0.0 && kplane > 0.0)
    my_put_pixel(framebuffer, scene.screen_pos.x,
		 scene.screen_pos.y, sfBlue);
}

void		raytrace_scene_sphere(t_my_framebuffer *framebuffer)
{
  sfVector3f	dir_vector;
  t_scene	scene;
  float		ksphere;
  float		kplane;

  init_scene(&scene);
  ksphere = 0.0;
  kplane = 0.0;
  while (scene.screen_pos.y < HEIGHT)
    {
      scene.screen_pos.x = 0;
      while (scene.screen_pos.x < WIDTH)
	{
	  dir_vector = calc_dir_vector(500.0, scene.screen_size,
				       scene.screen_pos);
	  ksphere = intersect_sphere(scene.eye_pos, dir_vector, 50.0);
	  kplane = intersect_plane(scene.eye_pos, dir_vector);
	  interpret_dist(kplane, ksphere, scene, framebuffer);
	  scene.screen_pos.x++;
	}
      scene.screen_pos.y++;
    }
}

void		raytrace_scene_cylinder(t_my_framebuffer *framebuffer)
{
  sfVector3f	dir_vector;
  t_scene	scene;
  float		kcylindre;
  float		kplane;

  init_scene(&scene);
  kcylindre = 0.0;
  kplane = 0.0;
  while (scene.screen_pos.y < HEIGHT)
    {
      scene.screen_pos.x = 0;
      while (scene.screen_pos.x < WIDTH)
	{
	  dir_vector = calc_dir_vector(500.0, scene.screen_size,
				       scene.screen_pos);
	  kcylindre = intersect_cylinder(scene.eye_pos, dir_vector, 50.0);
	  kplane = intersect_plane(scene.eye_pos, dir_vector);
	  interpret_dist(kplane, kcylindre, scene, framebuffer);
	  scene.screen_pos.x++;
	}
      scene.screen_pos.y++;
    }
}

void		raytrace_scene_cone(t_my_framebuffer *framebuffer)
{
  sfVector3f	dir_vector;
  t_scene	scene;
  float		kcone;
  float		kplane;

  init_scene(&scene);
  kcone = 0.0;
  kplane = 0.0;
  while (scene.screen_pos.y < HEIGHT)
    {
      scene.screen_pos.x = 0;
      while (scene.screen_pos.x < WIDTH)
	{
	  dir_vector = calc_dir_vector(500.0, scene.screen_size,
				       scene.screen_pos);
	  kcone = intersect_cone(scene.eye_pos, dir_vector, 50.0);
	  kplane = intersect_plane(scene.eye_pos, dir_vector);
	  interpret_dist(kplane, kcone, scene, framebuffer);
	  scene.screen_pos.x++;
	}
      scene.screen_pos.y++;
    }
}
