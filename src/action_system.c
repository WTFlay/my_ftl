/*
** action_system.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 3:04 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 3:04 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

void                repair_system(t_game *game, t_ship *ship)
{
    (void)game;
    system_repair(ship);
}

void                control_system(t_game *game, t_ship *ship)
{
    (void)game;
    system_control(ship);
}

void                stat(t_game *game, t_ship *ship) {
    (void) game;
    my_printf("hull: %d\n", ship->hull);
    my_printf("energy: %d\n", ship->ftl_drive->energy);
    my_printf("sector: %d\n", ship->navigation_tools->sector);
    my_printf("damage: %d\n", ship->weapon->damage);
    my_printf("evade: %d\n", ship->navigation_tools->evade);
    if (ship->container->nb_elem > 0)
    {
        my_printf("contenu du container %d:\n", ship->container->nb_elem);
        print_container(ship->container);
    }
    else
        my_printf("aucun freight dans votre container\n");
}

void                random_breakdown(t_ship *ship)
{
    int             random;

    random = random_int(1, 3);
    if (random == 1 &&
            my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    {
        free(ship->navigation_tools->system_state);
        ship->navigation_tools->system_state = my_strdup("offline");
        my_printf("votre système de navigation tombe en panne!\n");
    }
    else if (random == 2 &&
            my_strcmp(ship->weapon->system_state, "online") == 0)
    {
        free(ship->weapon->system_state);
        ship->weapon->system_state = my_strdup("offline");
        my_printf("système d'armement tombe en panne\n");
    }
    else if (random == 3 &&
            my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    {
        free(ship->ftl_drive->system_state);
        ship->ftl_drive->system_state = my_strdup("offline");
        my_printf("réacteur tombe en panne\n");
    }
}
