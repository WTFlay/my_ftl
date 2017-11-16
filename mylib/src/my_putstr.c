/*
** my_putstr.c for MY_PUTSTR in /home/schrie_f/etna/c/Jour03/workstation
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Wed Sep 30 09:11:09 2015 SCHRIEVER Flavien
** Last update Wed Sep 30 09:26:33 2015 SCHRIEVER Flavien
*/

#include "my.h"

void		my_putstr(char *str)
{
	if (str != NULL)
		write(1, str, (size_t) my_strlen(str));
}
