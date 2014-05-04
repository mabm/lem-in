/*
** move.c for  in /home/mediav_j/mabm/lem-in/lem_in
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May  3 17:00:36 2014 Jeremy Mediavilla
** Last update Sun May  4 16:19:12 2014 Geoffrey Merran
*/

#include "core.h"

void		move_next_room(t_map *map, t_ant *ant)
{
  t_room	*tmp;
  t_room	*cur;

  if (ant->room != 0)
    {
      cur = find_room(map, ant->wat->path[ant->room]);
      tmp = find_room(map, ant->way->path[ant->room - 1]);
      if (tmp->val == 0 || tmp == map->end)
	{
	  cur->val = 0;
	  if (tmp == map->end)
	    map->end->val = map->end->val + 1;
	  else
	    tmp->val = ant->id;
	  ant->room--;
	  printf("P%d-%s ", ant->id, tmp->name);
	}
    }
}

void	lem_in_take_a_selfie()
{


}

int		nbr_of_ways(t_path *path)
{
  t_way		*tmp;
  int		i;

  i = 0;
  tmp = path->way;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
