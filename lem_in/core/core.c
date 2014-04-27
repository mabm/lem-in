/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Sun Apr 27 18:38:23 2014 Jeremy Mediavilla
*/

#include "lem_in.h"
#include "main.h"

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

int		get_room_value(t_map *map, char *room_name)
{
  t_room	*tmp;

  tmp = find_room(map, room_name);
  return (tmp->val);
}

void		aff_path(t_access *path)
{
  printf("\nPath :\n");
  while (path != NULL)
    {
      printf("%s\n", path->name);
      path = path->next;
    }
  my_putchar('\n');
}

void		travel_rooms(t_map *map, char *room_name, t_access *path)
{
  t_room	*tmp;

  add_access(room_name, &path);
  /* aff_path(path); */
  printf("--Rooms linked to %s :\n", room_name);
  tmp = find_room(map, room_name);
  while (tmp->access != NULL)
    {
      printf("--%s\n", tmp->access->name);
      tmp->access = tmp->access->next;
    }
}

void		find_short_way(t_map *map)
{
  t_room	*tmp;
  t_access	*path;

  path = NULL;
  tmp = map->start;
  printf("\nrooms linked to room %s (start)\n", tmp->name);
  tmp->val = 0;
  while (tmp->access != NULL)
    {
      printf("-%s\n", tmp->access->name);
      tmp->val = 1;
      travel_rooms(map, tmp->access->name, path);
      tmp->access = tmp->access->next;
    }
}
