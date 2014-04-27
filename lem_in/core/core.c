/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Sun Apr 27 17:37:50 2014 Jeremy Mediavilla
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

void		travel_rooms(t_map *map, char *room_name)
{
  t_room	*tmp;
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

  tmp = map->start;
  printf("\nrooms linked to room %s (start)\n", tmp->name);
  tmp->val = 0;
  while (tmp->access != NULL)
    {
      printf("-%s\n", tmp->access->name);
      travel_rooms(map, tmp->access->name);
      tmp->access = tmp->access->next;
    }
}

void		launch_fct(t_map *map)
{
  
}
