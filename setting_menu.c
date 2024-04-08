/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** setting_menu
*/

#include "my.h"

void loading_fleches(my_rpg *rpg)
{
    rpg->text_fleche_d = sfTexture_createFromFile("img/fleche_d.png", NULL);
    rpg->fleche_droite = sfSprite_create();
    sfSprite_setTexture(rpg->fleche_droite, rpg->text_fleche_d, sfTrue);
    sfSprite_setPosition(rpg->fleche_droite, (sfVector2f){1050, 450});
    sfSprite_setScale(rpg->fleche_droite, (sfVector2f){0.4f, 0.4f});
    rpg->text_fleche_g = sfTexture_createFromFile("img/fleche_g.png", NULL);
    rpg->fleche_gauche = sfSprite_create();
    sfSprite_setTexture(rpg->fleche_gauche, rpg->text_fleche_g, sfTrue);
    sfSprite_setPosition(rpg->fleche_gauche, (sfVector2f){950, 452});
    sfSprite_setScale(rpg->fleche_gauche, (sfVector2f){0.4f, 0.4f});
    rpg->text_lum_plus = sfTexture_createFromFile("img/lum_plus.png", NULL);
    rpg->lum_plus = sfSprite_create();
    sfSprite_setTexture(rpg->lum_plus, rpg->text_lum_plus, sfTrue);
    sfSprite_setPosition(rpg->lum_plus, (sfVector2f){1050, 600});
    sfSprite_setScale(rpg->lum_plus, (sfVector2f){0.4f, 0.4f});
    rpg->text_lum_less = sfTexture_createFromFile("img/lum_less.png", NULL);
    rpg->lum_less = sfSprite_create();
    sfSprite_setTexture(rpg->lum_less, rpg->text_lum_less, sfTrue);
    sfSprite_setPosition(rpg->lum_less, (sfVector2f){950, 602});
    sfSprite_setScale(rpg->lum_less, (sfVector2f){0.4f, 0.4f});
}

void loading_setting_sprite(my_rpg *rpg)
{
    rpg->texture = sfTexture_createFromFile("img/jungle.gif", NULL);
    rpg->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->sprite, rpg->texture, sfTrue);

    rpg->text_set_menu = sfTexture_createFromFile("img/setting_menu.png", NULL);
    rpg->setting_menu = sfSprite_create();
    sfSprite_setTexture(rpg->setting_menu, rpg->text_set_menu, sfTrue);
    sfSprite_setPosition(rpg->setting_menu, (sfVector2f){630, 160});
    sfSprite_setScale(rpg->setting_menu, (sfVector2f){1.50f, 1.50f});

    rpg->text_home_butt = sfTexture_createFromFile("img/button_home.png", NULL);
    rpg->home_button = sfSprite_create();
    sfSprite_setTexture(rpg->home_button, rpg->text_home_butt, sfTrue);
    sfSprite_setPosition(rpg->home_button, (sfVector2f){700, 730});
    sfSprite_setScale(rpg->home_button, (sfVector2f){0.3f, 0.3f});

    loading_fleches(rpg);

}

void mouse_event_if(my_rpg *rpg, my_box *box, sfRenderWindow* window)
{
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        rpg->click_home = sfSprite_getGlobalBounds(rpg->home_button);
        if (sfFloatRect_contains(&rpg->click_home,
        rpg->event.mouseButton.x, rpg->event.mouseButton.y)) {
            sd_menu(rpg, box, window);
        }
        rpg->click_left = sfSprite_getGlobalBounds(rpg->fleche_gauche);
        if (sfFloatRect_contains(&rpg->click_left,
        rpg->event.mouseButton.x, rpg->event.mouseButton.y)) {
            sfMusic_setVolume(rpg->music, sfMusic_getVolume(rpg->music) - 10);
        }
        rpg->click_right = sfSprite_getGlobalBounds(rpg->fleche_droite);
        if (sfFloatRect_contains(&rpg->click_right,
        rpg->event.mouseButton.x, rpg->event.mouseButton.y)) {
            sfMusic_setVolume(rpg->music, sfMusic_getVolume(rpg->music) + 10);
        }
    }
}

void handle_mouse_events(my_rpg *rpg, my_box *box, sfRenderWindow* window)
{
    while (sfRenderWindow_pollEvent(window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        mouse_event_if(rpg, box, window);
    }
}

int open_setting_menu(my_rpg *rpg, my_box *box, sfRenderWindow* window)
{
    loading_setting_sprite(rpg);

    while (sfRenderWindow_isOpen(window)) {

        handle_mouse_events(rpg, box, window);

        sfRenderWindow_drawSprite(window, rpg->sprite, NULL);
        sfRenderWindow_drawSprite(window, rpg->setting_menu, NULL);
        sfRenderWindow_drawSprite(window, rpg->home_button, NULL);
        sfRenderWindow_drawSprite(window, rpg->fleche_droite, NULL);
        sfRenderWindow_drawSprite(window, rpg->fleche_gauche, NULL);
        sfRenderWindow_drawSprite(window, rpg->lum_plus, NULL);
        sfRenderWindow_drawSprite(window, rpg->lum_less, NULL);

        sfRenderWindow_display(window);
    }
    return 0;
}
