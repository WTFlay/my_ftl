/*
** my_getnbr.c for Jour05 in /home/schrie_f/etna/c/Jour05/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Fri Oct 02 15:24:02 2015 SCHRIEVER Flavien
** Last update Tue Oct 06 13:39:03 2015 SCHRIEVER Flavien
*/
#include "my.h"

int			test_nbr(char c, int *nbr, int *neg)
{
	if (c == '-' && *nbr == 0)
		*neg *= -1;
	else if (c == '+' && *nbr == 0)
		*neg *= 1;
	else if	(c == '0')
	{
		if (*nbr > 0)
			*nbr *= 10;
		else
			return (0);
	}
	else if (c >= '1' &&
		c <= '9')
	{
		if (*nbr > 0)
			*nbr *= 10;
		*nbr += c - '0';
	}
	else
		return (0);
	return (1);
}

int			my_getnbr(char *str)
{
	int		i;
	int		neg;
	int		nbr;
	neg = 1;
	nbr = 0;
	i = 0;
	while (i < my_strlen(str))
	{
		if (test_nbr(str[i], &nbr, &neg))
			i++;
		else
			return (nbr * neg);
	}
	return (nbr * neg);
}
