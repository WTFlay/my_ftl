/*
** button.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 09 10:05 PM 2017 SCHRIEVER Flavien
** Last update Nov 09 10:05 PM 2017 SCHRIEVER Flavien
*/

#include "engine2d.h"

t_button                           *create_button(SDL_Renderer *renderer, const t_action *action,
                                                  TTF_Font *font, SDL_Color colors[NB_COLOR])
{
    t_button                       *button;

    if (renderer == NULL || font == NULL)
        return (NULL);
    if ((button = malloc(sizeof(t_button))) == NULL)
        return (free_button(button, "error in malloc of button\n"));
    button->up = &colors[0];
    button->down = &colors[1];
    button->actual = button->up;
    button->is_down = 0;
    button->action = action;
    if ((button->text = create_text(renderer, button->action->name, font,
                                    *(button->actual))) == NULL)
        return (free_button(button, "error in create_text in create_button\n"));
    return (button);
}

void                                draw_button(SDL_Renderer *renderer, t_button *button, TTF_Font *font)
{
    t_text                          *text;

    if (button == NULL || button->text == NULL || font == NULL)
        return;
    if ((button->is_down && button->actual != button->down) ||
            (!button->is_down && button->actual != button->up))
    {
        button->actual = (button->is_down ? button->down : button->up);
        if ((text = create_text(renderer, button->text->label, font, *(button->actual))) == NULL)
            free_button(NULL, "cannot update color of button\n");
        else
        {
            text->sprite->pos->x = button->text->sprite->pos->x;
            text->sprite->pos->y = button->text->sprite->pos->y;
            free(button->text);
            button->text = text;
        }
    }
    draw_text(renderer, button->text);
}

int                                 handle_button(t_button *button, SDL_Event *event, t_engine *engine)
{
    SDL_Rect                        mouse;

    mouse.x = event->button.x;
    mouse.y = event->button.y;
    mouse.w = mouse.h = 1;
    if ((button->is_down = (event->button.state == SDL_PRESSED &&
                            SDL_HasIntersection(button->text->sprite->pos, &mouse))) == 1)
    {
        if (button->action->realize != NULL)
            button->action->realize(engine->game, engine->ship);
        else
            return (-1);
        return (1);
    }
    return (0);
}

t_button                            *free_button(t_button *button, char *message)
{
    if (message != NULL)
        my_printf("FREE_BUTTON: %s\n", message);
    if (button == NULL)
        return (NULL);
    if (button->text != NULL)
        free_text(button->text, NULL);
    free(button);
    return (NULL);
}
