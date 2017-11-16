/*
** my_nb_len.c for my_nb_len in /home/schrie_f/svn/c/Jour01/schrie_f/my_nb_len
** 
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
** 
** Started on  Mon Sep 28 16:01:58 2015 SCHRIEVER Flavien
** Last update Mon Sep 28 16:21:21 2015 SCHRIEVER Flavien
*/

#include "my.h"

int		my_nb_len(int n)
{
	int i;
	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}

	return (i);
}
