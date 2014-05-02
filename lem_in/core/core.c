/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Fri May  2 09:27:32 2014 Jeremy Mediavilla
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

int		nbr_of_access(t_map *map, char *room_name)
{
  int		i;
  t_room	*tmp;

  i = 0;
  tmp = find_room(map, room_name);
  while (tmp->access != NULL)
    {
      tmp->access = tmp->access->next;
      i++;
    }
  return (i);
}

void		aff_tiret(int val)
{
  int		i;

  i = -1;
  while (++i < val)
    {
      my_putchar('|');
      if ((i + 1) != val)
	my_putchar(' ');
    }
  my_putstr("__");
}

void		travel_rooms(t_map *map, t_room *current, int value)
{
  t_room	*access;
  t_access	*tmp;

  tmp = current->access;
  if (current == map->end)
    printf(" (END)");
  printf("\n");
  while (tmp != NULL && current != map->end)
    {
      access = find_room(map, tmp->name);
      if (access->val == -1 || access->val > value)
	{
	  access->val = value;
	  aff_tiret(value);
	  printf("%s [%i]", tmp->name, access->val);
	  travel_rooms(map, access, (value + 1));
	}
      tmp = tmp->next;
    }
}

void		room_backtracking(t_map *map, t_access **shortway)
{
  t_room	*current;

  if (map->end->val == -1)
    my_error(" ~ Error : No solution has been found to go outside ~\n");
  current = map->end;
  while (current != map->start)
    {
      while (get_room_value(map, current->access->name) != (current->val - 1))
	current->access = current->access->next;
      add_access(current->name, shortway);
      current = find_room(map, current->access->name);
    }
  add_access(map->start->name, shortway);
}

void		find_short_way(t_map *map)
{
  t_access	*shortway;

  shortway = NULL;
  printf("\n%s (start)", map->start->name);
  map->start->val = 0;
  travel_rooms(map, map->start, 1);
  room_backtracking(map, &shortway);
  aff_path(shortway);
}
