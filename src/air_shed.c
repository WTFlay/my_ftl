/*
** air_shed.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 10:44 AM 2017 SCHRIEVER Flavien
** Last update Nov 06 10:44 AM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

t_ship*         create_ship()
{
    t_ship      *ship;

    my_printf("construction du vaisseau en cours...\n");
    if ((ship = malloc(sizeof(t_ship))) == NULL)
    {
        my_printf("le vaisseau n'a pas pu etre construit par manque de materiaux\n");
        return (NULL);
    }
    ship->hull = 50;
    ship->weapon = NULL;
    ship->ftl_drive = NULL;
    ship->navigation_tools = NULL;
    ship->container = NULL;
    my_printf("amelioration du vaisseau termine!\n");
    return (ship);
}

int             add_weapon_to_ship(t_ship *ship)
{
    my_printf("ajout des armes en cours...\n");
    if (ship == NULL)
    {
        my_printf("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
        return (0);
    }
    if ((ship->weapon = malloc(sizeof(t_weapon))) == NULL)
    {
        my_printf("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
        return (0);
    }
    ship->weapon->damage = 10;
    if ((ship->weapon->system_state = my_strdup("online")) == NULL)
    {
        my_printf("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
        return (0);
    }
    my_printf("les armes on ete ajoutes avec succes!\n");
    return (1);
}

int             add_ftl_drive_to_ship(t_ship *ship)
{
    my_printf("ajout du reacteur en cours..\n");
    if (ship == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose le reacteur\n");
        return (0);
    }
    ;
    if ((ship->ftl_drive = malloc(sizeof(t_ftl_drive))) == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose le reacteur\n");
        return (0);
    }
    ship->ftl_drive->energy = 10;
    if ((ship->ftl_drive->system_state = my_strdup("online")) == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose le reacteur\n");
        return (0);
    }
    my_printf("le reacteur a ete ajoute avec succes!\n");
    return (1);
}

int             add_navigation_tools_to_ship(t_ship *ship)
{
    my_printf("ajout des outils de navigations...\n");
    if (ship == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose les outils de navigations\n");
        return (0);
    }
    if ((ship->navigation_tools = malloc(sizeof(t_navigation_tools))) == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose les outils de navigations\n");
        return (0);
    }
    if ((ship->navigation_tools->system_state = my_strdup("online")) == NULL)
    {
        my_printf("votre vaisseau a explose lorsque vous avez pose les outils de navigations\n");
        return (0);
    }
    ship->navigation_tools->sector = 0;
    ship->navigation_tools->evade = 25;
    my_printf("les outils de navigations ont ete ajoutes avec succes!\n");
    return (1);
}

void            free_ship(t_ship *ship)
{
    if (ship == NULL)
        return;
    if (ship->navigation_tools != NULL)
    {
        if (ship->navigation_tools->system_state != NULL)
            free(ship->navigation_tools->system_state);
        free(ship->navigation_tools);
    }
    if (ship->ftl_drive != NULL)
    {
        if (ship->ftl_drive->system_state != NULL)
            free(ship->ftl_drive->system_state);
        free(ship->ftl_drive);
    }
    if (ship->weapon != NULL)
    {
        if (ship->weapon->system_state != NULL)
            free(ship->weapon->system_state);
        free(ship->weapon);
    }
    if (ship->container != NULL)
        free_container(ship);
    free(ship);
}
