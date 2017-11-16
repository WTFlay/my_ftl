/*
** text.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 09 12:17 PM 2017 SCHRIEVER Flavien
** Last update Nov 09 12:17 PM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

t_text              *init_text(char *message)
{
    t_text          *text;

    if ((text = malloc(sizeof(t_text))) == NULL)
        return (free_text(text, "malloc t_text error in init_text\n"));
    text->sprite = NULL;
    if ((text->label = my_strdup(message)) == NULL)
        return (free_text(text, "error my_strdup label in text\n"));
    if ((text->sprite = malloc(sizeof(t_sprite))) == NULL)
        return (free_text(text, "malloc t_sprite error in init_text\n"));
    text->sprite->texture = NULL;
    if ((text->sprite->pos = malloc(sizeof(SDL_Rect))) == NULL)
        return (free_text(text, "malloc SDL_Rect error in init_text\n"));
    text->sprite->angle = text->sprite->pos->x = text->sprite->pos->y = 0;
    return (text);
}

t_text                 *create_text(SDL_Renderer *renderer, char *message,
                                    TTF_Font *font, SDL_Color color)
{
    SDL_Surface        *surface;
    t_text             *text;

    if (renderer == NULL || message == NULL || font == NULL)
        return (NULL);
    if ((text = init_text(message)) == NULL)
        return (free_text(text, NULL));
    if ((surface = TTF_RenderText_Blended(font, message, color)) == NULL)
        return (free_text(text, "TTF_RenderText_Blended error in create_text\n"));
    text->sprite->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (text->sprite->texture == NULL)
        return (free_text(text, "SDL_CreateTextureFromSurface error in\
reate_text\n"));
    if (SDL_QueryTexture(text->sprite->texture, NULL, NULL,
                         &text->sprite->pos->w, &text->sprite->pos->h) != 0)
        free_text(text, "SDL_QueryTexture error in create_text\n");
    return (text);
}

void                    draw_text(SDL_Renderer *renderer, t_text *text)
{
    if (renderer == NULL || text == NULL || text->sprite == NULL)
        return;
    draw_sprite(renderer, text->sprite);
}

t_text                  *free_text(t_text *text, char *message)
{
    if (message != NULL)
        my_printf("FREE_TEXT: %s\n", message);
    if (text == NULL)
        return (NULL);
    if (text->label != NULL)
        free(text->label);
    if (text->sprite != NULL)
        free_sprite(text->sprite, NULL);
    free(text);
    return (NULL);
}
