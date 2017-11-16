/*
** system_repair.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 5:00 PM 2017 SCHRIEVER Flavien
** Last update Nov 06 5:00 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

static const    t_repair_command repair_command[] =
        {
                {"ftl_drive", &ftl_drive_system_repair},
                {"navigation_tools", &navigation_tools_system_repair},
                {"weapon", &weapon_system_repair},
                {NULL, NULL}
        };

char*           update_status(char *status_to_repair)
{
    char*       status;

    status = my_strdup("online");
    if (status == NULL)
        return (NULL);
    if (status_to_repair != NULL)
        free(status_to_repair);
    status_to_repair = status;
    return (status_to_repair);
}

void            ftl_drive_system_repair(t_ship *ship)
{
    my_printf("reparation du reacteur en cours...\n");
    if (ship == NULL || ship->ftl_drive == NULL ||
            ((ship->ftl_drive->system_state = update_status(ship->ftl_drive->system_state)) == NULL))
    {
        my_printf("les reparations du reacteur ont echoue\n");
        return;
    }
    my_printf("reparation termine, systeme reacteur OK!\n");
}

void            navigation_tools_system_repair(t_ship *ship)
{
    my_printf("reparation du systeme de navigation en cours...\n");
    if (ship == NULL || ship->navigation_tools == NULL ||
            ((ship->navigation_tools->system_state = update_status(ship->navigation_tools->system_state)) == NULL))
    {
        my_printf("les reparations des outils de navigations ont echoue\n");
        return;
    }
    my_printf("reparation termine, systeme de navigation OK!\n");
}

void            weapon_system_repair(t_ship *ship)
{
    my_printf("reparation du systeme d'armement en cours...\n");
    if (ship == NULL || ship->weapon == NULL ||
            ((ship->weapon->system_state = update_status(ship->weapon->system_state)) == NULL))
    {
        my_printf("les reparations du systeme d'armement ont echoue\n");
        return;
    }
    my_printf("reparation termine, systeme d'armement OK!\n");
}

void                            system_repair(t_ship *ship)
{
    int                         i;
    char                        buffer[BUFFER_SIZE];
    const t_repair_command      *tmp;

    i = 0;
    my_init_str(buffer, BUFFER_SIZE, 0);
    tmp = &(repair_command[i]);
    my_printf("repair_system~> ");
    if (my_readin(buffer, BUFFER_SIZE) < 1)
    {
        my_printf("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
        return;
    }
    while (tmp->cmd != NULL)
    {
        if (my_strcmp(tmp->name, buffer) == 0)
        {
            tmp->cmd(ship);
            return;
        }
        tmp = &(repair_command[++i]);
    }
    my_printf("[SYSTEM FAILURE] : commande inconnue\n");
}
