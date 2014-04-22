/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Tue Apr 22 14:03:40 2014 Geoffrey Merran
*/

#include "main.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      printf("blabla\n");
    }
  else
    printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
