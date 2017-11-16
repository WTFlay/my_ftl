/*
** my_strstr.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 17:36:57 2015 SCHRIEVER Flavien
** Last update Sat Oct 03 17:06:05 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	i = 0;
	while (i < my_strlen(str))
	{
		j = 0;
		while (str[i] == to_find[j])
		{
				i++;
				j++;
		}
		if (j == my_strlen(to_find))
			return (&str[i - j]);
		i++;
	}
	return "null";
}
