/*
** my_word_size.c for Jour07 in /home/schrie_f/etna/c/Jour07/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Mon Oct 05 14:34:17 2015 SCHRIEVER Flavien
** Last update Mon Oct 05 14:40:25 2015 SCHRIEVER Flavien
*/

#include "my.h"

int			my_word_size(char *str)
{
	int		i;
	i = 0;
	while (my_is_char(str[i]))
		i++;
	return (i);
}
