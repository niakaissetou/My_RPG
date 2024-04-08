/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** loading_menu_sprite
*/

#include "my.h"

void loading_menu_button(my_rpg *rpg)
{
    rpg->text_button_play = sfTexture_createFromFile("img/play_butt.png", NULL);
    rpg->button_play = sfSprite_create();
    rpg->text_button_setting = sfTexture_createFromFile
    ("img/setting_button.png",NULL);
    rpg->button_setting = sfSprite_create();
    rpg->text_button_exit = sfTexture_createFromFile("img/exit_butt.png", NULL);
    rpg->button_exit = sfSprite_create();

    sfSprite_setTexture(rpg->button_play, rpg->text_button_play, sfTrue);
    sfSprite_setPosition(rpg->button_play, (sfVector2f){800, 320});
    sfSprite_setTexture(rpg->button_setting, rpg->text_button_setting, sfTrue);
    sfSprite_setPosition(rpg->button_setting, (sfVector2f){800, 470});
    sfSprite_setTexture(rpg->button_exit, rpg->text_button_exit, sfTrue);
    sfSprite_setPosition(rpg->button_exit, (sfVector2f){795, 600});
    sfSprite_setScale(rpg->button_play, (sfVector2f){0.7f, 0.7f});
    sfSprite_setScale(rpg->button_setting, (sfVector2f){0.7f, 0.7f});
    sfSprite_setScale(rpg->button_exit, (sfVector2f){0.7f, 0.7f});
}

void loading_menu_sprite(my_rpg *rpg)
{
    rpg->music = sfMusic_createFromFile("wondrous-waters-119518.ogg");
    sfMusic_setLoop(rpg->music, sfTrue);
    sfMusic_play(rpg->music);

    sfTexture* texture1 = sfTexture_createFromFile("img/frame-01.png", NULL);
    sfTexture* texture2 = sfTexture_createFromFile("img/frame-02.png", NULL);
    sfTexture* texture3 = sfTexture_createFromFile("img/frame-03.png", NULL);
    sfTexture* texture4 = sfTexture_createFromFile("img/frame-04.png", NULL);

    int i = 0;
    while (i < 4) {
    rpg->sprites[i] = sfSprite_create();
    i++;
    }
    sfSprite_setTexture(rpg->sprites[0], texture1, sfTrue);
    sfSprite_setTexture(rpg->sprites[1], texture2, sfTrue);
    sfSprite_setTexture(rpg->sprites[2], texture3, sfTrue);
    sfSprite_setTexture(rpg->sprites[3], texture4, sfTrue);

    loading_menu_button(rpg);
}
