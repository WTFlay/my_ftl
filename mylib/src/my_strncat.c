/*
** my_strncat.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 13:49:49 2015 SCHRIEVER Flavien
** Last update Thu Oct 01 13:54:44 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strncat(char *str1, char *str2, int n)
{
	int		i;
	int		size_str1;
	i = 0;
	size_str1 = my_strlen(str1);
	while (i < n)
	{
		str1[size_str1 + i] = str2[i];
		i++;
	}
	str1[size_str1 + i] = '\0';
	return (str1);
}
