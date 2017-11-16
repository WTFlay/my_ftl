/*
** engine2d.h for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 08 5:11 PM 2017 SCHRIEVER Flavien
** Last update Nov 08 5:11 PM 2017 SCHRIEVER Flavien
*/

#ifndef _MY_FTL_ENGINE2D_H_
#define _MY_FTL_ENGINE2D_H_

#include "ftl.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define         SPRITE_BACKGROUND   0
#define         SPRITE_PLAYER       1
#define         SPRITE_ENEMY        2
#define         ROTATION_PLAYER     90
#define         NB_SPRITE           3
#define         NB_BUTTON           8
#define         NB_STAT             2
#define         BACKGROUND_PNG      "resources/background.png"
#define         PLAYER_PNG          "resources/ship_player.png"
#define         ENEMY_PNG           "resources/ship_enemy.png"

#define         VERSION_TEXT        "my_ftl by schrie_f"

#define         HULL_TEXT           "HULL: "
#define         HULL_STAT           0

#define         SECTOR_TEXT         "SECTOR "
#define         SECTOR_STAT         1

#define         SCREEN_WIDTH        1920
#define         SCREEN_HEIGHT       1080

#define         FONT_SIZE           64
#define         FONT                "resources/sample.ttf"

#define         COLOR_TEXT          0
#define         COLOR_UP_BTN        0
#define         COLOR_DOWN_BTN      1
#define         COLOR_STAT          1
#define         NB_COLOR            2

typedef struct                      s_sprite
{
    SDL_Texture                    *texture;
    SDL_Rect                       *pos;
    int                             angle;
}                                   t_sprite;

typedef struct                      s_text
{
    char                            *label;
    t_sprite                        *sprite;
}                                   t_text;

typedef struct                      s_stat
{
    t_text                          *text;
    char                            *base;
    int                             *nbr;
    int                             last_nbr;
}                                   t_stat;

typedef struct                      s_button
{
    t_text                          *text;
    const t_action                  *action;
    SDL_Color                       *down;
    SDL_Color                       *up;
    SDL_Color                       *actual;
    int                             is_down;
}                                   t_button;

typedef struct                      s_2d
{
    SDL_Window                      *window;
    SDL_Renderer                    *renderer;
    TTF_Font                        *font;
    t_text                          *version;
    t_sprite                        *sprites[NB_SPRITE];
    t_stat                          *stats[NB_STAT];
    t_button                        *buttons[NB_BUTTON];
    t_engine                        *engine;
}                                   t_2d;

void                               *sdl_game(void *);
t_2d                               *create_2d(t_engine *);
void                               play_2d(t_2d *);
t_2d                               *free_2d(t_2d *, char *);

void                                gen_sprites(t_2d *, const char *[NB_SPRITE]);
void                                gen_stats(t_2d *, const SDL_Color[NB_COLOR]);
void                                gen_buttons(t_2d *, const SDL_Color[NB_COLOR]);
void                                draw_2d(t_2d *, const SDL_Color[NB_COLOR]);
int                                 process_2d(t_2d *, SDL_Event *);

t_sprite                            *init_sprite();
t_sprite                            *create_sprite(SDL_Renderer *, const char*, int, int, int);
t_sprite                            *create_background(SDL_Renderer *, const char*, int);
void                                draw_sprite(SDL_Renderer *, t_sprite *);
t_sprite                            *free_sprite(t_sprite *, char *);

t_text                              *init_text(char *);
t_text                              *create_text(SDL_Renderer *, char *, TTF_Font *, SDL_Color);
void                                draw_text(SDL_Renderer *, t_text *);
t_text                              *free_text(t_text *, char *);

t_stat                              *create_stat(SDL_Renderer *, char *, TTF_Font *, SDL_Color, int *);
void                                draw_stat(SDL_Renderer *, t_stat *, TTF_Font *, SDL_Color);
t_stat                              *free_stat(t_stat *, char *);
char                                *generate_stat_text(char *base, int stat);

t_button                            *create_button(SDL_Renderer *, const t_action *, TTF_Font *, SDL_Color[2]);
void                                draw_button(SDL_Renderer *, t_button *, TTF_Font *);
int                                 handle_button(t_button *, SDL_Event *, t_engine *);
t_button                            *free_button(t_button *, char *);

#endif //MY_FTL_ENGINE2D_H
