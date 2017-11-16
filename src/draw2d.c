/*
** draw2d.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 10 11:28 AM 2017 SCHRIEVER Flavien
** Last update Nov 10 11:28 AM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

static const char*                  const_button_names[NB_BUTTON] =
        {
                "attack", "detect", "jump", "getbonus",
                "repair_system", "control_system", "stat", "quit"
        };

void                    gen_sprites(t_2d *t2d,
                                   const char *texture_names[NB_SPRITE])
{
    int                 i;

    i = 0;
    if (t2d == NULL)
        return;
    if ((t2d->sprites[i] = create_background(t2d->renderer, texture_names[SPRITE_BACKGROUND], 0)) == NULL)
        my_printf("error in create %s background\n", texture_names[SPRITE_BACKGROUND]);
    while (++i < NB_SPRITE)
    {
        if ((t2d->sprites[i] = create_sprite(t2d->renderer, texture_names[i], 0, 0, 0)) == NULL)
            my_printf("error in create %s sprite\n", texture_names[i]);
    }
    if (t2d->sprites[SPRITE_PLAYER] != NULL)
    {
        t2d->sprites[SPRITE_PLAYER]->pos->x = SCREEN_WIDTH / 4 - t2d->sprites[SPRITE_PLAYER]->pos->w / 2;
        t2d->sprites[SPRITE_PLAYER]->angle = ROTATION_PLAYER;
        t2d->sprites[SPRITE_PLAYER]->pos->y = SCREEN_HEIGHT / 3 - t2d->sprites[SPRITE_PLAYER]->pos->h / 2;
    }
    if (t2d->sprites[SPRITE_ENEMY] != NULL)
    {
        t2d->sprites[SPRITE_ENEMY]->pos->x = 3 * SCREEN_WIDTH / 4 - t2d->sprites[SPRITE_ENEMY]->pos->w / 2;
        t2d->sprites[SPRITE_ENEMY]->pos->y = SCREEN_HEIGHT / 3 - t2d->sprites[SPRITE_ENEMY]->pos->h / 2;
        t2d->sprites[SPRITE_ENEMY]->angle = -ROTATION_PLAYER;
    }
}

void                                gen_stats(t_2d *t2d, const SDL_Color colors[NB_COLOR])
{
    if ((t2d->stats[HULL_STAT] = create_stat(t2d->renderer, HULL_TEXT, t2d->font, colors[COLOR_STAT], &t2d->engine->ship->hull)) != NULL)
    {
        t2d->stats[HULL_STAT]->text->sprite->pos->x = SCREEN_WIDTH / 8 - t2d->stats[HULL_STAT]->text->sprite->pos->w / 2;
        t2d->stats[HULL_STAT]->text->sprite->pos->y = 5 * SCREEN_HEIGHT / 8 - t2d->stats[HULL_STAT]->text->sprite->pos->h / 2;
    }
    if ((t2d->stats[SECTOR_STAT] = create_stat(t2d->renderer, SECTOR_TEXT, t2d->font,
                                               colors[COLOR_UP_BTN], &t2d->engine->ship->navigation_tools->sector)) != NULL)
    {
        t2d->stats[SECTOR_STAT]->text->sprite->pos->x = SCREEN_WIDTH / 8 - t2d->stats[SECTOR_STAT]->text->sprite->pos->w / 2;
        t2d->stats[SECTOR_STAT]->text->sprite->pos->y = 6 * SCREEN_HEIGHT / 8 - t2d->stats[SECTOR_STAT]->text->sprite->pos->h / 2;
    }
}

void                                gen_buttons(t_2d *t2d, const SDL_Color colors[2])
{
    t_button                        *button;
    SDL_Rect                        tmp;

    tmp.y = -1;
    tmp.w = 4 * SCREEN_WIDTH / 8;
    tmp.h = 5 * SCREEN_HEIGHT / 8;
    while (++tmp.y < NB_BUTTON)
    {
        button = NULL;
        tmp.x = -1;
        while (actions[++tmp.x].name != NULL)
        {
            if (my_strcmp(actions[tmp.x].name, (char *)const_button_names[tmp.y]) == 0 &&
                (button = create_button(t2d->renderer, &actions[tmp.x], t2d->font, (SDL_Color *)colors)) != NULL)
            {
                tmp.w += button->text->sprite->pos->w / 2;
                if (tmp.w >= SCREEN_WIDTH)
                {
                    tmp.w = 4 * SCREEN_WIDTH / 8 + button->text->sprite->pos->w / 2;
                    tmp.h += SCREEN_HEIGHT / 8;
                }
                button->text->sprite->pos->x = tmp.w - button->text->sprite->pos->w;
                button->text->sprite->pos->y = tmp.h;
            }
        }
        tmp.w += SCREEN_WIDTH / 8;
        t2d->buttons[tmp.y] = button;
    }
}

void                                draw_2d(t_2d *t2d, const SDL_Color colors[NB_COLOR])
{
    int                             i;

    SDL_RenderClear(t2d->renderer);
    i = -1;
    draw_sprite(t2d->renderer, t2d->sprites[SPRITE_BACKGROUND]);
    if (t2d->engine->game->enemy != NULL)
        draw_sprite(t2d->renderer, t2d->sprites[SPRITE_ENEMY]);
    draw_text(t2d->renderer, t2d->version);
    if (t2d->engine->ship->hull >= 0)
        draw_sprite(t2d->renderer, t2d->sprites[SPRITE_PLAYER]);
    i = -1;
    while (++i < NB_STAT)
        draw_stat(t2d->renderer, t2d->stats[i], t2d->font, colors[COLOR_STAT]);
    i = -1;
    while (++i < NB_BUTTON)
        draw_button(t2d->renderer, t2d->buttons[i], t2d->font);
    SDL_RenderPresent(t2d->renderer);
}

int                                 process_2d(t_2d *t2d, SDL_Event *event)
{
    int                             i;
    int                             handle;

    i = -1;
    while (++i < NB_BUTTON)
    {
        handle = handle_button(t2d->buttons[i], event, t2d->engine);
        if (handle == -1)
            return (1);
        if (handle == 1)
            process_game(t2d->engine->game, t2d->engine->ship);
    }
    return (0);
}
