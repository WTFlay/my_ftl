/*
** engine.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 07 7:34 PM 2017 SCHRIEVER Flavien
** Last update Nov 07 7:34 PM 2017 SCHRIEVER Flavien
*/

#include "ftl.h"

void*               classic_game(void *arg)
{
    t_engine        *engine;
    const t_action	*action;

    engine = (t_engine *)arg;
    if (engine == NULL || engine->game == NULL || engine->ship == NULL)
        return (NULL);
    action = NULL;
    print_actions(engine->game, engine->ship);
    while (!engine->game->end)
    {
        while ((action = read_action()) == NULL)
            my_printf("[SYSTEM FAILURE] : commande inconnue\n");
        if (action->realize != NULL)
        {
            action->realize(engine->game, engine->ship);
            if (action->count == 1)
                process_game(engine->game, engine->ship);
        }
        else
            engine->game->end = 1;
    }
    return (engine);
}
