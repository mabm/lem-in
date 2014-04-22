/*
** lem_in.h for lem_in in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 14:58:46 2014 Geoffrey Merran
** Last update Tue Apr 22 15:01:56 2014 Geoffrey Merran
*/

#ifndef LEM_IN_
# define LEM_IN_

typedef struct	s_room
{
  int		val;
  char		*name;
  int		size_access;
  struct s_room **access;
  struct s_room	*next;
}		t_room;

typedef struct	s_map
{
  t_room	*start;
  t_room	*end;
  t_room	*first;
}		t_map;

#endif /* LEM_IN_ */
