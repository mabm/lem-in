/*
** core.h for  in /home/nicolas/Workspace/lem_in/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr 22 03:12:44 2014 Nicolas Ades
** Last update Tue Apr 22 14:24:33 2014 Jeremy Mediavilla
*/

#ifndef CORE_H_
# define CORE_H_

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stats.h>
# include <fcntl.h>
# include "my.h"

typedef struct	s_room
{
  char		*name;
  int		size_access;
  t_room	**access;
  t_room	*next;
  int		valu;
}

typedef struct	s_map
{
  t_room	*start;
  t_room	*end;
  t_room	*first;
}		t_map;

#endif /* CORE_H_ */
