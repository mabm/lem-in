/*
** parser.c for parser in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 14:57:57 2014 Geoffrey Merran
** Last update Fri Apr 25 20:04:44 2014 Geoffrey Merran
*/

#include "parser.h"

void	parse_command(char *buffer, int *step, t_map *map)
{
  printf("%s\n", buffer);
}

void	parse_data2(char *buffer, int *step, t_map *map)
{
  char	**tab2;

  tab2 = my_strd_to_wordtab(buffer, "-");
  if (my_strlen_tabs(tab2) == 1)
    get_nb_ants(tab2, step, map);
  else if (my_strlen_tabs(tab2) == 2)
    {
      
    }
  else
    {
      printf("Invalid line : %s\n", buffer);
      exit(EXIT_FAILURE);
    }
  free(tab2);
}

void	parse_data(char *buffer, int *step, t_map *map)
{
  char	**tab;

  tab = my_strd_to_wordtab(buffer, " ");
  if (my_strlen_tabs(tab) == 1)
    parse_data2(tab[0], step, map);
  else if (my_strlen_tabs(tab) == 3)
    {
      get_room(tab, step, map);
      printf("%s\n", buffer);
    }
  else
    {
      printf("Invalid line : %s\n", buffer);
      exit(EXIT_FAILURE);
    }
  free(tab);
}

void	parse_type(int type, char *buffer, int *step, t_map *map)
{
  if (type == COMMENTARY_TYPE)
    printf("%s\n", buffer);
  else if (type == COMMAND_TYPE)
    parse_command(buffer, step, map);
  else
    parse_data(buffer, step, map);
}

t_map	*parse_lemin()
{
  t_map	*map;
  char	*buffer;
  int	step;
  int	type;

  init_map(&map);
  step = 0;
  while ((buffer = get_next_line(0)) != NULL)
    {
      type = get_line_type(buffer);
      parse_type(type, buffer, &step, map);
      free(buffer);
    }
  return (map);
}
