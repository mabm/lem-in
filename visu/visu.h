/*
** visu.h for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Apr 30 15:50:26 2014 Joris Bertomeu
** Last update Fri May  2 09:06:05 2014 Joris Bertomeu
*/

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <stdlib.h>
# include <SDL/SDL_ttf.h>
# include "gnl.h"

# define HEIGHT 768
# define WIDTH 1024

typedef struct s_elm t_elm;
struct s_elm
{
  int	x;
  int	y;
  char	*name;
};

typedef struct s_system t_system;
struct s_system
{
  int		current;
  t_elm		element[512];
  SDL_Surface	*screen;
};
