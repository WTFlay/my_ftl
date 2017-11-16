/*
** stat.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 09 5:54 PM 2017 SCHRIEVER Flavien
** Last update Nov 09 5:54 PM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

t_stat      *create_stat(SDL_Renderer *renderer,
                        char *text, TTF_Font *font, SDL_Color color, int *init)
{
    char    *msg;
    t_stat  *stat;

    if ((stat = malloc(sizeof(t_stat))) == NULL)
        return (free_stat(stat, "error malloc stat in create_stat\n"));
    stat->text = NULL;
    stat->nbr = init;
    stat->last_nbr = *stat->nbr;
    stat->base = my_strdup(text);
    if ((msg = generate_stat_text(text, *stat->nbr)) == NULL)
        return (free_stat(stat, "error generate stat_text in create_state\n"));
    if ((stat->text = create_text(renderer, msg, font, color)) == NULL)
        return  (free_stat(stat, "error in stat-text in create_stat\n"));
    free(msg);
    return (stat);
}

void            draw_stat(SDL_Renderer *renderer,
                          t_stat *stat, TTF_Font *font, SDL_Color color)
{
    t_text      *new_text;
    char        *msg;

    if (stat == NULL)
        return;
    if (stat->last_nbr != *stat->nbr)
    {
        if ((msg = generate_stat_text(stat->base, *stat->nbr)) == NULL)
            return;
        else if ((new_text = create_text(renderer, msg, font, color)) == NULL)
            my_printf("cannot create_text in draw_stat\n");
        else
        {
            new_text->sprite->pos->x = stat->text->sprite->pos->x;
            new_text->sprite->pos->y = stat->text->sprite->pos->y;
            free_text(stat->text, NULL);
            stat->text = new_text;
        }
        stat->last_nbr = *stat->nbr;
        free(msg);
    }
    draw_sprite(renderer, stat->text->sprite);
}

char                *generate_stat_text(char *base, int stat)
{
    char            *msg;
    char            *nbr;
    int             size;

    if (base == NULL || (nbr = my_get_nbr(stat)) == NULL)
        return (NULL);
    size = 0;
    size = my_strlen(nbr) + my_strlen(base);
    if ((msg = malloc(sizeof(char) * (size + 1))) == NULL || size == 0)
    {
        free(nbr);
        return (NULL);
    }
    msg = my_init_str(msg, size + 1, 0);
    msg = my_strcpy(msg, base);
    msg = my_strcat(msg, nbr);
    msg[size] = 0;
    return (msg);
}

t_stat                              *free_stat(t_stat *stat, char *message)
{
    if (message != NULL)
        my_printf("FREE_STAT: %s\n", message);
    if (stat->base != NULL)
        free(stat->base);
    if (stat == NULL)
        return (NULL);
    if (stat->text != NULL)
        free_text(stat->text, NULL);
    free(stat);
    return (NULL);
}
