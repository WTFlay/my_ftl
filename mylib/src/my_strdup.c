/*
** my_strdup.c for Jour07 in /home/schrie_f/etna/c/Jour07/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Mon Oct 05 09:54:33 2015 SCHRIEVER Flavien
** Last update Mon Oct 05 10:05:08 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strdup(char *str)
{
	int			size;
	char		*copy;

	size = my_strlen(str);
	if ((copy = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	my_strcpy(copy, str);
	copy[size] = 0;
	return (copy);
}
