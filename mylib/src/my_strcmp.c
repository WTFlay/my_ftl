/*
** my_strcmp.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 11:00:49 2015 SCHRIEVER Flavien
** Last update Sat Oct 03 19:06:45 2015 SCHRIEVER Flavien
*/

#include "my.h"

int			my_strcmp(char *s1, char *s2)
{
	int		i;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (s1 == NULL ? -1 : 1);
	while (i < my_strlen(s1) || i < my_strlen(s2))
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}
