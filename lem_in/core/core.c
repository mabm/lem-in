/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Mon Apr 28 19:30:13 2014 Jeremy Mediavilla
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

int		nbr_of_access(t_map *map, char *room_name)
{
  int		i;
  t_room	*tmp;

  i = 0;
  tmp = find_room(map, room_name);
  while (tmp->access != NULL)
    {
      i++;
      tmp->access = tmp->access->next;
    }
  return (i);
}

int		nbr_of_uninitialized_access(t_map *map, char *room_name)
{
  int		i;
  t_room	*tmp;
  t_room	*to_check;

  i = 0;
  tmp = find_room(map, room_name);
  while (tmp->access != NULL)
    {
      to_check = find_room(map, tmp->access->name);
      if (to_check->val == -1)
	i++;
      tmp->access = tmp->access->next;
    }
  return (i);
}

void		aff_tiret(int val)
{
  int		i;

  i = 0;
  while (i < val)
    {
      my_putchar('-');
      i++;
    }
}

void		travel_rooms(t_map *map, t_room *current, int value)
{
  t_room	*access;
  t_access	*tmp;

  tmp = current->access;
  if (current == map->end)
    printf("(END)\n");
  while (tmp != NULL && current != map->end)
    {
      access = find_room(map, tmp->name);
      /* printf("room : %s %i > %i ?\n", access->name, access->val, value); */
      if (access->val == -1 || access->val > value)
	{
	  access->val = value;
	  aff_tiret(value);
	  printf("%s [%i]\n", tmp->name, access->val);
	  travel_rooms(map, access, (value + 1));
	}
      tmp = tmp->next;
    }
}

void		find_short_way(t_map *map)
{
  printf("\n%s (start)\n", map->start->name);
  map->start->val = 0;
  travel_rooms(map, map->start, 1);
}
