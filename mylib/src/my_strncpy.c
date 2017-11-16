/*
** my_strncpy.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 10:00:32 2015 SCHRIEVER Flavien
** Last update Thu Oct 01 10:44:37 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strncpy(char *dest, char *src, int n)
{
	int		i;
	i = 0;
	if (my_strlen(src) < n)
	{
		while (i < n)
		{
			if (i < my_strlen(src))
				dest[i] = src[i];
			else
				dest[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
