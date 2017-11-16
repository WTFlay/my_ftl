/*
** my_is_char.c for Jour07 in /home/schrie_f/etna/c/Jour07/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Mon Oct 05 14:28:24 2015 SCHRIEVER Flavien
** Last update Mon Oct 05 14:32:22 2015 SCHRIEVER Flavien
*/

#include "my.h"

int			my_is_char(char c)
{
	if ((c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
