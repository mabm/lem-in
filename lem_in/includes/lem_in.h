/*
** lem_in.h for lem_in in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 14:58:46 2014 Geoffrey Merran
** Last update Thu Apr 24 17:42:21 2014 Geoffrey Merran
*/

#ifndef LEM_IN_
# define LEM_IN_

typedef	struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef	struct		s_access
{
  char			*name;
  struct s_access	*next;
}			t_access;

typedef struct	s_room
{
  int		val;
  char		*name;
  t_pos		pos;
  int		size_access;
  t_access	**access;
  struct s_room	*next;
}		t_room;

typedef struct	s_map
{
  int		nb_ants;
  t_room	*start;
  t_room	*end;
  t_room	*head;
  t_room	*tail;
}		t_map;

#endif /* LEM_IN_ */
