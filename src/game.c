/*
** game.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 12:08 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 12:08 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

t_game              *create_game(t_ship *ship)
{
    t_game          *game;

    if (ship == NULL || !add_weapon_to_ship(ship) ||
            !add_navigation_tools_to_ship(ship) ||
            !add_ftl_drive_to_ship(ship) || !add_container_to_ship(ship))
        return (NULL);
    if ((game = malloc(sizeof(t_game))) == NULL)
        return (NULL);
    game->end = 0;
    game->detect = 0;
    game->enemy = NULL;
    game->last = NULL;
    return (game);
}

const t_action      *read_action()
{
    const t_action  *action;
    char            buffer[BUFFER_SIZE];

    my_printf("> ");
    if (my_init_str(buffer, BUFFER_SIZE, 0) == NULL ||
            (my_readin(buffer, BUFFER_SIZE) == -1))
        return (NULL);
    if ((action = actions) == (NULL))
        return (NULL);
    while (action->name != NULL)
    {
        if (my_strcmp(action->name, buffer) == 0)
            return (action);
        action++;
    }
    return (NULL);
}

void                process_game(t_game *game, t_ship *ship)
{
    if (game->enemy != NULL)
        enemy_attack(game, ship);
    if (ship->ftl_drive == NULL || ship->navigation_tools == NULL)
        return;
    if (ship->hull <= 0 || ship->ftl_drive->energy == 0 ||
            (game->enemy == NULL &&
             ship->navigation_tools->sector == MAX_SECTOR))
        game->end = 1;
}

void                free_game(t_game *game)
{
    if (game == NULL)
        return;
    if (game->enemy != NULL)
        free(game->enemy);
    if (game->last != NULL)
        free(game->last);
    free(game);
}

void                        print_actions(t_game *game, t_ship *ship)
{
    (void)game;
    (void)ship;
    int                     i;

    i = 0;
    my_printf("liste des commandes:\n");
    while (actions[i].name != NULL)
        my_printf("\t[%s]\n", actions[i++].name);
}
