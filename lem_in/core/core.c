/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Fri May  2 18:44:38 2014 Geoffrey Merran
*/

#include "core.h"

t_room		*find_room(t_map *map, char *room_name)
{
  t_room	*tmp;

  tmp = map->head;
  while (tmp != NULL)
    {
      if (strcmp(room_name, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		travel_rooms(t_map *map, t_room *current, int value, t_path *path)
{
  t_room	*access;
  t_access	*tmp;

  tmp = current->access;
  if (current == map->end)
    {
      get_path(path, value);
      printf(" (END)");
    }
  printf("\n");
  while (tmp != NULL && current != map->end)
    {
      access = find_room(map, tmp->name);
      if (access->val == -1 || access->val > value)
	{
	  access->val = value;
	  aff_tiret(value);
	  printf("%s [%i]", tmp->name, access->val);
	  add_access(tmp->name, &path->access);
	  travel_rooms(map, access, (value + 1), path);
	  remove_last_access(&path->access);
	}
      tmp = tmp->next;
    }
}

void		init_path(t_path **path)
{
  *path = my_xmalloc(sizeof(**path));
  (*path)->access = NULL;
  (*path)->way = NULL;
}

void		find_short_way(t_map *map)
{
  t_path	*path;

  init_path(&path);
  add_access(map->start->name, &path->access);
  printf("\n%s (start)", map->start->name);
  map->start->val = 0;
  travel_rooms(map, map->start, 1, path);
  if (path->way == NULL)
    my_error("~ Error : there are no way found to the final room ~\n");
  aff_way(path->way);
}
