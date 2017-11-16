/*
** action_ship.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 1:36 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 1:36 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

void                attack(t_game *game, t_ship *ship)
{
    if (game->enemy == NULL)
        my_printf("aucun enemie a attaquer\n");
    else if (ship->weapon == NULL)
        my_printf("votre vaiseau n'a pas de système d'armement\n");
    else {
        if (my_strcmp(ship->weapon->system_state, "online") != 0)
            my_printf("votre système d'armement est offline !\n");
        else
        {
            my_printf("vous infligez %d dégats à l'enemie\n", ship->weapon->damage);
            game->enemy->hull -= ship->weapon->damage;
        }
    }
}

void                detect(t_game *game, t_ship *ship)
{
    if (game->detect == 0)
    {
        my_printf("il n'y a aucun container dans le secteur\n");
        return;
    }
    if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    {
        my_printf("votre système de navigation est en panne, vous ne \
pouvez faire de détéction\n");
        return;
    }
    drop_random_freights(ship);
    game->detect--;
}

void                jump(t_game *game, t_ship *ship)
{
    if (game->enemy != NULL)
    {
        my_printf("vous ne pouvez pas jumper face à un enemie !\n");
        return;
    }
    if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    {
        my_printf("votre moteur est en panne, vous ne pouvez pas jumper\n");
        return;
    }
    game->detect = INIT_DETECTION;
    ship->ftl_drive->energy--;
    ship->navigation_tools->sector++;
    my_printf("vous jumpez au secteur %d !\n", ship->navigation_tools->sector);
    if (random_bool(PERC_SPAWN_ENEMY))
    {
        upgrade_enemy(game);
        if (game->enemy != NULL)
            my_printf("vous rencontrez un enemie avec %d pdv!\n", game->enemy->hull);
    }
}

void                getbonus(t_game *game, t_ship *ship)
{
    (void)game;
    get_bonus(ship);
}

int                random_bonus(t_ship *ship)
{
    t_freight      *freight;

    if ((freight = malloc(sizeof(t_freight))) == NULL)
        return (0);
    freight->item = NULL;
    if (!random_bool(PERC_DROP_CRAP))
    {
        int random = random_int(1, 100);
        if (random <= PERC_COLLECT_BONUS)
            freight->item = my_strdup("energy");
        else if (random <= PERC_COLLECT_BONUS*2)
            freight->item = my_strdup("attackbonus");
        else if (random <= PERC_COLLECT_BONUS*3)
            freight->item = my_strdup("evadebonus");
    }
    if (freight->item == NULL && (freight->item = my_strdup("scrap")) == NULL)
    {
        free(freight);
        return (0);
    }
    add_freight_to_container(ship, freight);
    return (1);
}
