/*
** my_init.c for draft_nov in /home/flay/works/draft_nov
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 05 3:14 PM 2017 SCHRIEVER Flavien
** Last update Nov 05 3:14 PM 2017 SCHRIEVER Flavien
*/

#include "my.h"

char        *my_init_str(char *str, int len, char c)
{
    int     i;

    if (str == NULL)
        return (NULL);
    i = -1;
    while (++i < len)
        str[i] = c;
    return (str);
}
