/*
** fill_map.c for fillmap in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 16:01:08 2014 Geoffrey Merran
** Last update Fri Apr 25 20:37:50 2014 Geoffrey Merran
*/

#include "parser.h"

void	get_nb_ants(char **tab, int *step, t_map *map)
{
  if (!my_str_isnum(tab[0]))
    {
      printf("Non decimal value non-allowed : %s\n", tab[0]);
      exit(EXIT_FAILURE);
    }
  else
    {
      if (*step != 0)
	my_error("Invalid syntax : check how to build a map\n");
      map->nb_ants = atoi(tab[0]);
      *step = 1;
      printf("%s\n", tab[0]);
    }
}

int	is_valid_room_name(char *str)
{
  int	i;

  if (!my_str_isalpha(str))
    return (0);
  if (str[0] == 'P')
    {
      if (strlen(str) > 1)
	{
	  i = 0;
	  while (str[++i])
	    {
	      if (!my_isdigit(str[i]))
		return (1);
	    }
	}
      return (0);
    }
  return (1);
}

int		is_existing_room(char *new, t_room *list)
{
  t_room	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, new) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void	get_room(char **tab, int *step, t_map *map)
{
  if (is_valid_room_name(tab[0]))
    {
      if (my_str_isnum(tab[1]) && my_str_isnum(tab[2]))
	{
	  if (!is_existing_room(tab[0], map->head))
	    {
	      if (*step == 1 || *step == 2)
		{
		  add_room(tab, map);
		  *step = 2;
		}
	      else
		my_error("Invalid syntax : check how to build a map\n");
	    }
	  else
	    my_error("Invalid room name : room already added\n");
	}
      else
	my_error("Invalid position : only decimal number allowed\n");
    }
  else
    my_error("Invalid room name (only alphanumeric and not P[number]\n");
}

