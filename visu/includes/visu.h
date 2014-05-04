/*
** visu.h for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Apr 30 15:50:26 2014 Joris Bertomeu
** Last update Sun May  4 12:04:31 2014 Joris Bertomeu
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SDL/SDL.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <stdlib.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_rotozoom.h>
# include "gnl.h"

# define HEIGHT 768
# define WIDTH 1024

typedef struct s_elm t_elm;
struct s_elm
{
  int	x;
  int	y;
  char	*name;
  int	func;
  int	nbr_ants;
};

typedef struct s_coor t_coor;
struct s_coor
{
  int	x;
  int	y;
};

typedef struct s_ants t_ants;
struct s_ants
{
  char	*name;
  char	*box;
};

typedef struct s_system t_system;
struct s_system
{
  int		current;
  t_elm		element[512];
  SDL_Surface	*screen;
  SDL_Surface	*map;
  int		nbr;
  int		nbr_box;
  int		nbr_fourm;
  int		nbr_ants;
  t_coor	pos;
  t_ants	ants[1024];
  int		tour;
  int		func;
  int		speed;
};
