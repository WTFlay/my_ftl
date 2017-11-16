/*
** my_putchar.c for my_putchar.c in /home/schrie_f/svn/C/Jour01/schrie_f/my_putchar
** 
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
** 
** Started on  Mon Sep 28 09:55:55 2015 SCHRIEVER Flavien
** Last update Mon Sep 28 14:04:09 2015 SCHRIEVER Flavien
*/

#include "my.h"

void		my_putchar(char c)
{
	write(1, &c, 1);
}
