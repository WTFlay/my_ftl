/*
** my_put_nbr.c for Jour04 in /home/schrie_f/etna/c/Jour05/workspace
**
** Made by SCHRIEVER Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Fri Oct 02 14:41:30 2015 SCHRIEVER Flavien
** Last update Fri Oct 02 15:23:04 2015 SCHRIEVER Flavien
*/
#include "my.h"

void		show_tab(char *tab, int size)
{
	int		i;
	i = size - 1;
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
}

char 		*my_get_nbr(int n)
{
	char	*tab_int;
	int		i;
	int		size_nbr = my_nb_len(n);
	if ((tab_int = malloc(size_nbr * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return my_strdup("-2147483648");
	else {
		if (n < 0) {
			write(1, "-", 1);
			n *= -1;
		}
		i = size_nbr - 1;
		while (i >= 0) {
			tab_int[i] = (n % 10) + '0';
			n /= 10;
			i--;
		}
		tab_int[size_nbr] = 0;
		return (tab_int);
	}

}

void		my_put_nbr(int n)
{
	char 	*nbr;
    if ((nbr = my_get_nbr(n)) != NULL)
    {
		my_putstr(nbr);
        free(nbr);
	}
}
