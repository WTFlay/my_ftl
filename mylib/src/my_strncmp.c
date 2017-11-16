/*
** my_strncmp.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 11:26:32 2015 SCHRIEVER Flavien
** Last update Thu Oct 01 11:42:21 2015 SCHRIEVER Flavien
*/

#include "my.h"

int			my_strncmp(char *s1, char *s2, int n)
{
	int		i;
	i = 0;
	while (i < n)
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
