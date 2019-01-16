/*
** change_dir.c for change_dir.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:06:36 2017 thibaut trouve
** Last update Tue Jan 24 15:06:08 2017 thibaut trouve
*/

#include "my.h"

int	change_path(t_path *path, char **tab, t_stat file)
{
  if (tab[1][0] == '/')
      return (test_chdirpath(tab));
  stat(tab[1], &file);
  getcwd(path->old_pwd, 2000);
  chdir(tab[1]);
  path->new_path = get_cd_path(path, tab);
  if (access(path->new_path, F_OK) != 0)
    {
      my_printf("%s: No such file or directory.\n", tab[1]);
      return (INEXISTANT);
    }
  else if (((file.st_mode & S_IFMT) != S_IFDIR) &&
	   (access(tab[1], F_OK) == 0))
    {
      my_printf("%s: Not a directory.\n", tab[1]);
      return (NOT_DIR);
    }
  getcwd(path->pwd, 2000);
  return (0);
}

void	change_directory(char **tab, char ***my_env)
{
  t_stat        file;
  t_path        path;
  int           status;

  if (tab[2] != NULL)
    {
      my_printf("cd: Too many arguments.\n");
      return ;
    }
  if (tab[1] == NULL)
    return (go_home(my_env, &(path.tmp)));
  if (tab[1][0] == '-' && tab[1][1] == '\0')
    go_back(&path, my_env);
  else
    if (((status = change_path(&path, tab, file)) == INEXISTANT) ||
	(status == NOT_DIR))
      return ;
  my_setenv(my_env, "OLDPWD", path.old_pwd);
  my_setenv(my_env, "PWD", path.pwd);
  return ;
}

void	go_home(char ***my_env, char *tmp[2000])
{
  if (get_var_env_value(*my_env, "HOME") != NULL)
    {
      my_setenv(my_env, "OLDPWD", getcwd(*tmp, 2000));
      my_setenv(my_env, "PWD", get_var_env_value(*my_env, "HOME"));
      chdir(get_var_env_value(*my_env, "HOME"));
    }
  return ;
}

void	go_back(t_path *path, char ***my_env)
{
  path->old_tmp = get_var_env_value(*my_env, "OLDPWD");
  if (path->old_tmp == NULL)
    return ;
  path->tmp = get_var_env_value(*my_env, "PWD");
  chdir(path->old_tmp);
  my_strcpy(path->pwd, path->old_tmp);
  my_strcpy(path->old_pwd, path->tmp);
  return ;
}

char	*get_cd_path(t_path *path, char **tab)
{
  path->new_path =
    malloc(sizeof(char) * my_strlen(path->old_pwd) + my_strlen(tab[1]) + 2);
  if (path->new_path == NULL)
    return (NULL);
  my_strcpy(path->new_path, path->old_pwd);
  my_strcat(path->new_path, "/");
  my_strcat(path->new_path, tab[1]);
  return (path->new_path);
}
