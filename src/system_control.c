/*
** system_control.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 4:21 PM 2017 SCHRIEVER Flavien
** Last update Nov 06 4:21 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

void            ftl_drive_system_check(t_ship *ship)
{
    my_printf("verification du reacteur en cours...\n");
    if (ship == NULL || ship->ftl_drive == NULL ||
            my_strcmp(ship->ftl_drive->system_state, "online") != 0)
        my_printf("reacteur hors service!");
    else
        my_printf("reacteur OK!\n");
}

void            navigation_tools_system_check(t_ship *ship)
{
    my_printf("verification du systeme de navigation en cours...\n");
    if (ship == NULL || ship->navigation_tools == NULL ||
            my_strcmp(ship->navigation_tools->system_state, "online") != 0)
        my_printf("systeme de navigation hors service!\n");
    else
        my_printf("systeme de navigation OK!\n");
}

void            weapon_system_check(t_ship *ship)
{
    my_printf("verification du systeme d'armement en cours...\n");
    if (ship == NULL || ship->weapon == NULL ||
            my_strcmp(ship->weapon->system_state, "online") != 0)
        my_printf("systeme d'armement hors service!\n");
    else
        my_printf("systeme d'armement OK!\n");
}

void            system_control(t_ship *ship)
{
    ftl_drive_system_check(ship);
    navigation_tools_system_check(ship);
    weapon_system_check(ship);
}
