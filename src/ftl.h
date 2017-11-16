/*
** ftl.h for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 10:18 AM 2017 SCHRIEVER Flavien
** Last update Nov 06 10:18 AM 2017 SCHRIEVER Flavien
*/

#ifndef MY_FTL_FTL_H
#define MY_FTL_FTL_H

#include "../mylib/src/my.h"
#include <stdlib.h>
#include <time.h>

#define                     BUFFER_SIZE         512

#define                     PERC_SPAWN_ENEMY    30
#define                     PERC_UP_ENEMY       50
#define                     PERC_BREAKDOWN      20
#define                     PERC_LOOSE_ENERGY   50
#define                     PERC_DROP_CRAP      70
#define                     PERC_COLLECT_BONUS  33
#define                     INIT_DAMAGE_ENEMY   10
#define                     INIT_HULL_ENEMY     20
#define                     INIT_DETECTION      1
#define                     NB_DROP_FREIGHT     10
#define                     MAX_SECTOR          10
#define                     NB_FREIGHT_TYPES    4

#define                     ENABLE_UP           1
#define                     DISABLE_UP          0

typedef struct              s_weapon
{
    char                    *system_state;
    int                     damage;
}                           t_weapon;

typedef struct              s_ftl_drive
{
    char                    *system_state;
    int                     energy;
}                           t_ftl_drive;

typedef struct              s_navigation_tools
{
    char                    *system_state;
    int                     sector;
    int                     evade;
}                           t_navigation_tools;

typedef struct              s_freight
{
    char                    *item;
    struct s_freight        *next;
    struct s_freight        *prev;
}                           t_freight;

typedef struct              s_container
{
    t_freight               *first;
    t_freight               *last;
    int                     nb_elem;
}                           t_container;

typedef struct              s_ship
{
    int                     hull;
    t_weapon                *weapon;
    t_ftl_drive             *ftl_drive;
    t_navigation_tools      *navigation_tools;
    t_container             *container;
}                           t_ship;

typedef struct              s_repair_command
{
    char                    *name;
    void                    (*cmd)(t_ship *);
}                           t_repair_command;

typedef struct              s_bonus
{
    char                    *name;
    void                    (*bonus)(t_ship*);
}                           t_bonus;

typedef struct              s_enemy
{
    int                     hull;
    int                     damage;
}                           t_enemy;

typedef struct              s_game
{
    int                     detect;
    int                     end;
    t_enemy                 *enemy;
    t_enemy                 *last;
}                           t_game;

typedef struct              s_action
{
    char                    *name;
    void                    (*realize)(t_game *, t_ship *);
    int                     count;
}                           t_action;

typedef struct              s_engine
{
    t_game                  *game;
    t_ship                  *ship;
}                           t_engine;

t_ship                      *create_ship();
int                         add_weapon_to_ship(t_ship *);
int                         add_navigation_tools_to_ship(t_ship *);
int                         add_ftl_drive_to_ship(t_ship *);
void                        free_ship(t_ship *);

int                         add_container_to_ship(t_ship *);
void                        add_freight_to_container(t_ship *, t_freight *);
void                        del_freight_from_container(t_ship *, t_freight *);
void                        get_bonus(t_ship *);
void                        free_container(t_ship *);

void                        ftl_drive_system_check(t_ship *);
void                        navigation_tools_system_check(t_ship *);
void                        weapon_system_check(t_ship *);
void                        system_control(t_ship *);

void                        ftl_drive_system_repair(t_ship *ship);
void                        navigation_tools_system_repair(t_ship *ship);
void                        weapon_system_repair(t_ship *ship);
void                        system_repair(t_ship *ship);

void                        attack_bonus(t_ship *ship);
void                        evade_bonus(t_ship *ship);
void                        energy_bonus(t_ship *ship);
void                        handle_freight(t_ship *ship, t_freight *freight);
void                        drop_random_freights(t_ship *ship);

t_game                      *create_game(t_ship *);
void                        process_game(t_game *, t_ship *);
const t_action              *read_action();
void                        free_game(t_game *);
void                        print_actions(t_game *, t_ship *);

int                         random_int(int min, int max);
int                         random_bool(int ratio_yes);

void                        attack(t_game *, t_ship *);
void                        detect(t_game *, t_ship *);
void                        jump(t_game *, t_ship *);
void                        getbonus(t_game *, t_ship *);
int                         random_bonus(t_ship *);

void                        repair_system(t_game *, t_ship *);
void                        control_system(t_game *, t_ship *);
void                        stat(t_game *, t_ship *);
void                        random_breakdown(t_ship *);

void                        count_freights(t_container *container, int* tab);
void                        print_counts(int *tab);
void                        print_result(t_ship *);
void                        print_container(t_container *);

t_enemy                     *new_enemy();
t_enemy                     *copy_enemy(t_enemy *, int is_up);
void                        upgrade_enemy(t_game *);
void                        apply_enemy_attack(t_enemy *enemy, t_ship *ship);
void                        enemy_attack(t_game *, t_ship *);

void                        *classic_game(void *);

static const        t_action actions[] =
        {
                {"attack", &attack, 1},
                {"detect", &detect, 1},
                {"jump", &jump, 1},
                {"getbonus", &getbonus, 1},
                {"repair_system", &repair_system, 1},
                {"control_system", &control_system, 0},
                {"stat", &stat, 0},
                {"help", &print_actions, 0},
                {"quit", NULL, 0},
                {NULL, NULL, 0}
        };


#endif /* MY_FTL_FTL_H */
