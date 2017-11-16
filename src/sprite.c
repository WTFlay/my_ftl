/*
** sprite.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 09 10:29 AM 2017 SCHRIEVER Flavien
** Last update Nov 09 10:29 AM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

t_sprite        *init_sprite()
{
    t_sprite    *sprite;

    if ((sprite = malloc(sizeof(t_sprite))) == NULL)
        return (free_sprite(sprite, "malloc error in init_sprite\n"));
    sprite->texture = NULL;
    if ((sprite->pos = malloc(sizeof(t_sprite))) == NULL)
        return (free_sprite(sprite, "malloc error in init_sprite\n"));
    sprite->pos->x = 0;
    sprite->pos->y = 0;
    return (sprite);
}

t_sprite            *create_sprite(SDL_Renderer *renderer, const char *path,
                                   int x, int y, int angle)
{
    SDL_Surface     *img;
    t_sprite        *sprite;

    if ((sprite = init_sprite()) == NULL)
        return (NULL);
    sprite->pos->x = x;
    sprite->pos->y = y;
    sprite->angle = angle;
    img = IMG_Load(path);
    if (img == NULL)
        return (free_sprite(sprite, "IMG_Load error in create_sprite\n"));
    sprite->texture = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
    if (sprite->texture == NULL)
        return (free_sprite(sprite, "SDL_CreateTextureFromSurface error in \
create_sprite\n"));
    if (SDL_QueryTexture(sprite->texture, NULL, NULL, &sprite->pos->w,
                         &sprite->pos->h) != 0)
        free_sprite(sprite, "SDL_QueryTexture error in create_sprite\n");
    return (sprite);
}

t_sprite                *create_background(SDL_Renderer *renderer,
                                           const char* path, int angle)
{
    t_sprite            *sprite;

    if (renderer == NULL || path == NULL)
        return (NULL);
    if ((sprite = create_sprite(renderer, path, 0, 0, angle)) == NULL)
        return (free_sprite(sprite, "error in malloc of background"));
    free(sprite->pos);
    sprite->pos = NULL;
    return (sprite);
}

void            draw_sprite(SDL_Renderer *renderer, t_sprite *sprite)
{
    if (renderer == NULL || sprite == NULL || sprite->texture == NULL)
        return;
    SDL_RenderCopyEx(renderer, sprite->texture, NULL, sprite->pos,
                     sprite->angle, NULL, SDL_FLIP_NONE);
}

t_sprite        *free_sprite(t_sprite *sprite, char *msg)
{
    if (msg != NULL)
        my_printf("FREE_SPRITE: %s\n", msg);
    if (sprite == NULL)
        return (NULL);
    if (sprite->pos != NULL)
        free(sprite->pos);
    if (sprite->texture != NULL)
        SDL_DestroyTexture(sprite->texture);
    free(sprite);
    return (NULL);
}
