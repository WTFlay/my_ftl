/*
** enemy.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 3:08 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 3:08 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

t_enemy*                    new_enemy()
{
    t_enemy*                enemy;

    if ((enemy = malloc(sizeof(t_enemy))) == NULL)
        return (NULL);
    enemy->hull = INIT_HULL_ENEMY;
    enemy->damage = INIT_DAMAGE_ENEMY;
    return (enemy);
}

t_enemy*                    copy_enemy(t_enemy *enemy, int is_up)
{
    t_enemy                 *copy;

    if (enemy == NULL)
        return (new_enemy());
    if ((copy = malloc(sizeof(t_enemy))) == NULL)
        return (NULL);
    copy->damage = enemy->damage + (is_up == 1 ? (enemy->damage * PERC_UP_ENEMY / 100) : 0);
    copy->hull = enemy->hull + (is_up == 1 ? (enemy->hull * PERC_UP_ENEMY / 100) : 0);
    return (copy);
}

void                        upgrade_enemy(t_game *game)
{
    t_enemy                 *tmp;

    if (game->last == NULL)
    {
        if ((game->enemy = new_enemy()) == NULL)
            return;
        if ((game->last = copy_enemy(game->enemy, DISABLE_UP)) == NULL)
        {
            free(game->enemy);
            game->enemy = NULL;
        }
    }
    else
    {
        if ((game->enemy = copy_enemy(game->last, ENABLE_UP)) == NULL)
            return;
        tmp = game->last;
        if ((game->last = copy_enemy(game->enemy, DISABLE_UP)) != NULL)
            free(tmp);
    }
}

void                        apply_enemy_attack(t_enemy *enemy, t_ship *ship)
{
    if (enemy == NULL || ship == NULL)
        return;
    if (random_bool(ship->navigation_tools->evade))
    {
        my_printf("l'enemie a tenté d'attaquer mais vous avez esquivez\n");
        return;
    }
    my_printf("l'enemie attaque et infligue %d dégats\n",enemy->damage);
    ship->hull -= enemy->damage;
    if (ship->hull < 0)
        ship->hull = 0;
    my_printf("il vous reste %d pdv\n", ship->hull);
    if (random_bool(PERC_BREAKDOWN))
        random_breakdown(ship);
}

void                        enemy_attack(t_game *game, t_ship *ship)
{
    if (game == NULL || game->enemy == NULL || ship == NULL)
        return;
    if (game->enemy->hull > 0)
        apply_enemy_attack(game->enemy, ship);
    else
    {
        my_printf("l'enemie a été détruit\n");
        free(game->enemy);
        game->enemy = NULL;
        if (random_bool(PERC_LOOSE_ENERGY))
        {
            ship->ftl_drive->energy--;
            my_printf("durant le combat, vous avez perdu 1 energie...\n");
        }
    }
}
