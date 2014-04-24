/*
** parser.h for parser in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 15:02:56 2014 Geoffrey Merran
** Last update Thu Apr 24 15:35:33 2014 Geoffrey Merran
*/

#ifndef PARSER_
# define PARSER_
# include <stdlib.h>
# include "lem_in.h"
# include "my.h"

/*
** Initialisation
*/

void	init_map(t_map **map);

/*
** Parsing
*/

t_map	*parse_lemin();

#endif /* PARSER_ */
