/*
** sort.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:20:41 2014 Joris Bertomeu
** Last update Sun May  4 12:31:36 2014 Joris Bertomeu
*/

#include "visu.h"

int	sort_id(t_system *sys, char *name)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (sys->element[i].name != NULL)
	{
	  if (strcmp(sys->element[i].name, name) == 0)
	    return (i);
	}
      i++;
    }
  return (-1);
}

int	sort_id_ant(t_system *sys, char *name)
{
  int	i;

  i = 0;
  while (i < 1024)
    {
      if (sys->ants[i].name != NULL)
	{
	  if (strcmp(sys->ants[i].name, name) == 0)
	    return (i);
	}
      i++;
    }
  return (-1);
}

void	set_color(SDL_Color *color)
{
  color->r = 255;
  color->g = 255;
  color->b = 255;
}

void	save_box(char *name, t_coor *pos, t_system *sys, int func)
{
  if (func == 1)
    sys->element[sys->nbr_box].nbr_ants = sys->nbr_ants;
  else
    sys->element[sys->nbr_box].nbr_ants = 0;
  sys->element[sys->nbr_box].x = pos->x * 40 + 80;
  sys->element[sys->nbr_box].y = pos->y * 40 + 80;
  sys->element[sys->nbr_box].func = func;
  sys->element[sys->nbr_box].name = xmalloc(strlen(name) * sizeof(*name));
  strcpy(sys->element[sys->nbr_box].name, name);
}

void	init_coor(t_coor *pos)
{
  pos->x = 0;
  pos->y = 0;
}