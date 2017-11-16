/*
** my_strcpy.c for Jour04 in /home/schrie_f/etna/c/Jour04/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Thu Oct 01 09:46:08 2015 SCHRIEVER Flavien
** Last update Sat Oct 03 19:37:39 2015 SCHRIEVER Flavien
*/

#include "my.h"

char		*my_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	while (i < my_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}	
	return (dest);
}
