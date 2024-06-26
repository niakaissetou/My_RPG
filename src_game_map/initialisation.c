/*
** EPITECH PROJECT, 2023
** init_struct_anime_t
** File description:
** anime_t_init$
*/
#include "my_map.h"

anime_t *init_anime(void)
{
    anime_t *anim = malloc(sizeof(anime_t));
    anim->clock = sfClock_create();
    anim->sprite_sans = sfSprite_create();
    anim->texture_sans = sfTexture_createFromFile("sans.png", NULL);
    (anim->rect).top = 0;
    (anim->rect).left = 0;
    (anim->rect).width = 105;
    (anim->rect).height = 135;
    (anim->pos).x = 20;
    (anim->pos).y = 840;
    (anim->scale).x = 0.4;
    (anim->scale).y = 0.4;
    (anim->mouv).x = 7; (anim->mouv).y = 2;
    sfSprite_setTextureRect(anim->sprite_sans, anim->rect);
    sfSprite_setTexture(anim->sprite_sans, anim->texture_sans, sfTrue);
    anim->livre = sfSprite_create();
    anim->text_livre = sfTexture_createFromFile("img/livre.png", NULL);
    (anim->pos_livre).x = 360;
    (anim->pos_livre).y = 580;
    return anim;
}

maps_t *init_maps_s(void)
{
    maps_t *maps = malloc(sizeof(maps_t));

    maps->sprite_sous_map = sfSprite_create();
    maps->texture_sous = sfTexture_createFromFile("sous_map.png", NULL);
    (maps->scale).x = 1.0;
    (maps->scale).y = 1.05;
    maps->sprite = sfSprite_create();
    maps->texture = sfTexture_createFromFile("font.png", NULL);
    (maps->center).x = 210;
    (maps->center).y = 740;
    (maps->size).x = 500;
    (maps->size).y = 400;
    (maps->size_map).x = 420;
    (maps->size_map).y = 320;
    return maps;
}
