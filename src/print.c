/*
** print.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 3:06 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 3:06 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

static const char*            freight_names[NB_FREIGHT_TYPES] =
        {
                "scrap", "energy", "attackbonus", "evadebonus"
        };

void                        print_result(t_ship *ship)
{
    if (ship->hull <= 0)
        my_printf("vous avez perdu, votre vaiseau a été détruit...\n");
    else if (ship->navigation_tools != NULL && ship->ftl_drive != NULL)
    {
        if (ship->navigation_tools->sector == MAX_SECTOR)
            my_printf("vous avez gagné, vous avez atteind le dernier secteur!\n");
        else if (ship->ftl_drive->energy <= 0)
            my_printf("vous avez perdu, votre vaiseau n'a plus d'energie\n");
    }
}

void                        count_freights(t_container *container, int* tab)
{
    int                     pos;
    t_freight               *freight;

    if (container == NULL || tab == NULL)
        return;
    freight = container->first;
    while (freight != NULL)
    {
        pos = 0;
        while (pos < NB_FREIGHT_TYPES)
        {
            if (my_strcmp(freight->item, (char *)(freight_names[pos])) == 0)
            {
                tab[pos]++;
                pos = NB_FREIGHT_TYPES;
            }
            pos++;
        }
        freight = freight->next;
    }
}

void                        print_counts(int *tab)
{
    int                     pos;

    pos = -1;
    while (++pos < NB_FREIGHT_TYPES)
    {
        if (tab[pos] > 0)
            my_printf("%dx %s\n", tab[pos], freight_names[pos]);
    }
}

void                        print_container(t_container *container)
{
    int                     freight_count[NB_FREIGHT_TYPES] = {0};

    if (container == NULL)
        return;
    count_freights(container, freight_count);
    print_counts(freight_count);
}
