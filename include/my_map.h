/*
** EPITECH PROJECT, 2023
** my_h
** File description:
** h_my
*/

#ifndef MY_MAP_H_
    #define MY_MAP_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderTexture.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System.h>
    #include <stdio.h>
    #include <curses.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <time.h>
    #include "../my.h"

typedef struct anime_s {
    sfRenderWindow *window;
    sfIntRect rect;
    float seconds;
    sfVector2f mouv;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *sprite_sans;
    sfTexture *texture_sans;
    sfClock *clock;
    sfSprite *livre;
    sfTexture *text_livre;
    sfVector2f pos_livre;
} anime_t;

typedef struct maps_s {
    sfSprite *sprite_sous_map;
    sfTexture *texture_sous;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f center;
    sfVector2f size;
    sfVector2f size_map;
}maps_t;

int resume(sfRenderWindow *window, my_rpg *rpg);
int handle_collision(long unsigned int x, long unsigned int y);
maps_t *init_maps_s(void);
anime_t *sprite_animation_u(anime_t *animation, sfRenderWindow *window);
anime_t *sprite_animation_d(anime_t *animation, sfRenderWindow *window);
anime_t *sprite_animation_l(anime_t *animation, sfRenderWindow *window);
anime_t *sprite_animation_r(anime_t *animation, sfRenderWindow *window);
anime_t *init_anime(void);
int sprite_dis(sfEvent event, sfRenderWindow *window);
int while_for_display(sfRenderWindow *window, my_rpg *rpg,
sfView *v, anime_t *a);
int animation_on_key(anime_t *animation, sfRenderWindow *window);
int display_window(my_rpg *rpg, sfRenderWindow *window);
int test_rect_coll(sfEvent event, sfRenderWindow *window);
#endif
