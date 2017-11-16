/*
** my_str_to_wordtab.c for Jour07 in /home/schrie_f/etna/c/Jour07/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Mon Oct 05 10:10:38 2015 SCHRIEVER Flavien
** Last update Mon Oct 05 14:35:59 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		**my_str_to_wordtab(char *str)
{
	int			i;
	int			pos;
	int			size;
	char		**tableau;
	tableau = malloc(sizeof(char *) * (my_nbr_word(str) + 1));
	i = 0;
	size = 0;
	pos = 0;
	while (i < my_nbr_word(str))
	{
		size = my_word_size(str + pos);
		if (size > 0)
		{
			tableau[i] = malloc(sizeof(char) * (size + 1));
			my_strncpy(tableau[i], str + pos, size);
			tableau[i][size] = '\0';
			i++;
		}
		pos += size + 1;
	}
	tableau[my_nbr_word(str)] = '\0';
	return (tableau);
}
