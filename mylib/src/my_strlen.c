/*
** file.c for draft_nov in /home/flay/works/draft_nov
**
** Made by SCHRIEVER Flavien
** Login    <schrie_f@etna-alternance.net>
**
** Started on  Nov 05 11:57 AM 2017 SCHRIEVER Flavien
** Last update Nov 05 11:57 AM 2017 SCHRIEVER Flavien
*/
#include "my.h"

int     my_strlen(char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\0');
    return (i);
}