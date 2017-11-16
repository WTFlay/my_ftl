/*
** engine2d.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 08 5:11 PM 2017 SCHRIEVER Flavien
** Last update Nov 08 5:11 PM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

static const char*      const_texture_names[] =
        {
                BACKGROUND_PNG, PLAYER_PNG, ENEMY_PNG
        };

static const SDL_Color  const_colors[] =
        {
                {255, 255, 255, 255},
                {255, 0, 0, 255}
        };

t_2d            *create_2d(t_engine *engine)
{
    t_2d        *t2d;

    if (engine == NULL || engine->ship == NULL || engine->game == NULL)
        return (NULL);
    if ((t2d = malloc(sizeof(t_2d))) == NULL)
        return (free_2d(NULL, "error malloc t2d\n"));
    t2d->engine = engine;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return (free_2d(NULL, "SDL_Init error\n"));
    if (TTF_Init() != 0)
        return (free_2d(NULL, "TTF_init error\n"));
    if ((t2d->font = TTF_OpenFont(FONT, FONT_SIZE)) == NULL)
        return (free_2d(t2d, "TTF_OpenFont error\n"));
    if ((t2d->window = SDL_CreateWindow("my_ftl",
                                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN)) == NULL)
        return (free_2d(t2d, "SDL_CreateWindow error\n"));
    if ((t2d->renderer = SDL_CreateRenderer(t2d->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
        return (free_2d(t2d, "SDL_CreateRenderer error\n"));
    gen_sprites(t2d, const_texture_names);
    gen_stats(t2d, const_colors);
    gen_buttons(t2d, const_colors);
    if ((t2d->version = create_text(t2d->renderer, VERSION_TEXT, t2d->font, const_colors[COLOR_TEXT])) == NULL)
        my_printf("error in create_text of version\n");
    else
        t2d->version->sprite->pos->x = t2d->version->sprite->pos->y = 0;
    return (t2d);
}

void            play_2d(t_2d *t2d)
{
    SDL_Event e;
    int quit = 0;

    if (t2d == NULL || t2d->engine == NULL || t2d->engine->game == NULL)
        return;
    while (!quit && !t2d->engine->game->end)
    {
        while (SDL_PollEvent(&e))
            quit = (e.type == SDL_QUIT || process_2d(t2d, &e));
        draw_2d(t2d, const_colors);
    }
}

void            *sdl_game(void *arg)
{
    t_2d        *t2d;
    t_engine    *engine;

    engine = (t_engine *)arg;
    if (engine == NULL || engine->ship == NULL || engine->game == NULL)
        return (NULL);
    if ((t2d = create_2d(engine)) != NULL)
        play_2d(t2d);
    free_2d(t2d, NULL);
    return (engine);
}

t_2d*           free_2d(t_2d *t2d, char *message)
{
    int         i;

    if (message != NULL)
        my_printf("FREE 2D: %s\n", message);
    if ((!(SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO)) || t2d == NULL)
    {
        SDL_Quit();
        return (NULL);
    }
    i = -1;
    while (++i < NB_SPRITE)
    {
        if (t2d->sprites[i] != NULL)
            free_sprite(t2d->sprites[i], NULL);
    }
    i = -1;
    if (TTF_WasInit())
    {
        if (t2d->version != NULL)
            free_text(t2d->version, NULL);
        while (++i < NB_STAT) {
            if (t2d->stats[i] != NULL)
                free_stat(t2d->stats[i], NULL);
        }
        i = -1;
        while (++i < NB_BUTTON) {
            if (t2d->buttons[i] != NULL)
                free_button(t2d->buttons[i], NULL);
        }
        TTF_CloseFont(t2d->font);
    }
    if (t2d->renderer != NULL)
        SDL_DestroyRenderer(t2d->renderer);
    if (t2d->window != NULL)
        SDL_DestroyWindow(t2d->window);
    SDL_Quit();
    free(t2d);
    return (NULL);
}
