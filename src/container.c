/*
** container.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 12:30 PM 2017 SCHRIEVER Flavien
** Last update Nov 06 12:30 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

int             add_container_to_ship(t_ship *ship)
{
    my_printf("ajout du container en cours...\n");
    if (ship == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose le container\n");
        return (0);
    }
    if ((ship->container = malloc(sizeof(t_container))) == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose le container\n");
        return (0);
    }
    ship->container->first = NULL;
    ship->container->last = NULL;
    ship->container->nb_elem = 0;
    my_printf("le container a ete ajoute avec succes!\n");
    return (1);
}

void            add_freight_to_container(t_ship *ship, t_freight *freight)
{
    if (ship == NULL || ship->container == NULL || freight == NULL)
        return;
    freight->next = NULL;
    freight->prev = NULL;
    if (ship->container->last == NULL)
        ship->container->first = ship->container->last = freight;
    else
    {
        ship->container->last->next = freight;
        freight->prev = ship->container->last;
        ship->container->last = freight;
    }
    ship->container->nb_elem++;
}

void            del_freight_from_container(t_ship *ship, t_freight *freight)
{
    t_freight   *tmp;

    if (ship == NULL || ship->container == NULL || freight == NULL)
        return ;
    tmp = ship->container->first;
    while (tmp != NULL && tmp != freight)
        tmp = tmp->next;
    if (tmp == freight)
    {
        if (tmp->prev != NULL)
            tmp->prev->next = tmp->next;
        else
            ship->container->first = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
        else
            ship->container->last = tmp->prev;
        if (tmp->item != NULL)
            free(tmp->item);
        free(tmp);
        ship->container->nb_elem--;
    }
}

void            get_bonus(t_ship *ship)
{
    t_freight   *freight;
    t_freight   *next;

    if (ship == NULL || ship->container == NULL)
        return;
    next = freight = ship->container->first;
    while (freight != NULL)
    {
        next = freight->next;
        handle_freight(ship, freight);
        freight = next;
    }
}

void            free_container(t_ship *ship)
{
    t_freight   *freight;

    if (ship == NULL || ship->container == NULL)
        return;
    freight = ship->container->first;
    while (freight != NULL)
    {
        del_freight_from_container(ship, freight);
        freight = ship->container->first;
    }
    free(ship->container);
}
