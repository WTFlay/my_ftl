/*
** my_strcat.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 11:48:12 2015 SCHRIEVER Flavien
** Last update Sat Oct 03 18:12:57 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strcat(char *str1, char *str2)
{
	int		i;
	int		size_str1;

	i = 0;
	size_str1 = my_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[size_str1 + i] = str2[i];
		i++;
	}
	str1[size_str1 + i] = '\0';
	return (str1);
}
