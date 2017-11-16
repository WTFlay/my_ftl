/*
** random.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 2:39 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 2:39 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

int             random_int(int min, int max)
{
    return ((int)(random() % max) + min);
}

int             random_bool(int perc)
{
    int rdm = ((int)random() % 100) + 1;
    return (rdm <= perc);
}
