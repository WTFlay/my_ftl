/*
** my_readin.c for draft_nov in /home/flay/works/draft_nov
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 05 2:44 PM 2017 SCHRIEVER Flavien
** Last update Nov 05 2:44 PM 2017 SCHRIEVER Flavien
*/

#include "my.h"

void        my_set_readin_noblock()
{
    int     flags;

    flags = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, flags | O_NONBLOCK);
}

int         my_readin(char *str, int len)
{
    int     res;

    res = (int) read(0, str, (size_t) len);
    if (res > 1)
        str[res-- - 1] = 0;
    return (res);
}
