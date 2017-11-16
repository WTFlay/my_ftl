/*
** bonus.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 10:29 AM 2017 SCHRIEVER Flavien
** Last update Nov 07 10:29 AM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

static const        t_bonus bonus[] =
        {
                {"attackbonus", &attack_bonus},
                {"evadebonus", &evade_bonus},
                {"energy", &energy_bonus},
                {"scrap", NULL},
                {NULL, NULL}
        };

void                attack_bonus(t_ship *ship)
{
    if (ship->weapon != NULL)
    {
        my_printf("votre attaque augmente de 5\n");
        ship->weapon->damage += 5;
    }
}

void                evade_bonus(t_ship *ship)
{
    if (ship->navigation_tools != NULL)
    {
        my_printf("votre esquive augmente de 3\n");
        ship->navigation_tools->evade += 3;
    }
}

void                energy_bonus(t_ship *ship)
{
    if (ship->ftl_drive != NULL)
    {
        my_printf("vous gagnez 1 point d'energie\n");
        ship->ftl_drive->energy += 1;
    }
}

void                handle_freight(t_ship *ship, t_freight *freight)
{
    const t_bonus   *tmp;

    if (freight->item != NULL)
    {
        if ((tmp = bonus) == NULL)
            return;
        while (tmp->name != NULL)
        {
            if (my_strcmp(tmp->name, freight->item) == 0)
            {
                if (tmp->bonus != NULL)
                    tmp->bonus(ship);
                del_freight_from_container(ship, freight);
                return;
            }
            tmp++;
        }
    }
}

void                drop_random_freights(t_ship *ship)
{
    int             i;

    i = 0;
    while (i < NB_DROP_FREIGHT)
    {
        if (random_bonus(ship))
            i++;
    }
}
