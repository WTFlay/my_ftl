/*
** my_swap.c for my_swap in /home/schrie_f/etna/c/Jour03/workstation
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Wed Sep 30 09:35:53 2015 SCHRIEVER Flavien
** Last update Wed Sep 30 09:43:02 2015 SCHRIEVER Flavien
*/

#include "my.h"

void		my_swap(int *a, int *b)
{
	int		c;
	c = *b;
	*b = *a;
	*a = c;
}
