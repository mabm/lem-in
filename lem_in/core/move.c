/*
** move.c for  in /home/mediav_j/mabm/lem-in/lem_in
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May  3 17:00:36 2014 Jeremy Mediavilla
** Last update Sat May  3 18:03:11 2014 Jeremy Mediavilla
*/

#include "core.h"

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

void		lem_in_take_a_selfie(t_path *path, int nb_ants)
{
  int		size;
  int		i;
  int		tmp;

  tmp = 0;
  size = nbr_of_ways(path);
  printf("TEKASS MERRAN JE FAIS DES TEST\n\n");
  while (nb_ants > 0)
    {
      if (size > 1)
	{
	  i = 0;
	  while (i < size)
	    {
	      if (nb_ants < size && size != 1)
		size--;
	      printf("On envoie dans le %i eme chemin le plus court\n", (size - i));
	      tmp++;
	      i++;
	      nb_ants--;
	    }
	}
      else
	{
	  printf("on envoie dans LE chemin le plus court\n");
	  tmp++;
	  nb_ants--;
	}
    }
  printf("On a envoyé : %i entités\n", tmp);
}
