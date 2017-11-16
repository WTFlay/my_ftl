/*
** my_nbr_word.c for Jour07 in /home/schrie_f/etna/c/Jour07/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Mon Oct 05 14:32:53 2015 SCHRIEVER Flavien
** Last update Mon Oct 05 14:37:16 2015 SCHRIEVER Flavien
*/

#include "my.h"

int			my_nbr_word(char *str)
{
	int		i;
	int		nb_mot;
	i = 0;
	nb_mot = 0;
	while (str[i] != '\0')
	{
		if (my_is_char(str[i - 1]) &&
			!my_is_char(str[i]))
			nb_mot++;
		i++;
	}
	if (i == 0)
		return (0);
	if (i > 0 && nb_mot == 0)
		return (1);
	return (nb_mot + 1);
}
