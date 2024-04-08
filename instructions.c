/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** instructions
*/

#include "my.h"
#include "my_map.h"
#include <SFML/Window/Keyboard.h>

void key_event(my_rpg *rpg, sfRenderWindow* window, my_box *box)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyReturn) {
            resume(window, rpg);
        }
    }
}

void instruc_mouse_event(my_rpg *rpg, sfRenderWindow* window, my_box *box)
{
    while (sfRenderWindow_pollEvent(window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        key_event(rpg, window, box);
    }
}

void instruction(my_rpg *rpg, sfRenderWindow* window, my_box *box)
{
    rpg->text_instruc_fond = sfTexture_createFromFile("img/jungle.gif", NULL);
    rpg->instruc_fond = sfSprite_create();
    sfSprite_setTexture(rpg->instruc_fond, rpg->text_instruc_fond, sfTrue);

    rpg->text_lettre = sfTexture_createFromFile("img/lettre.png", NULL);
    rpg->lettre = sfSprite_create();
    sfSprite_setTexture(rpg->lettre, rpg->text_lettre, sfTrue);
    sfSprite_setPosition(rpg->lettre, (sfVector2f){470, 35});

    while (sfRenderWindow_isOpen(window)) {
        instruc_mouse_event(rpg, window, box);

        sfRenderWindow_drawSprite(window, rpg->instruc_fond, NULL);
        sfRenderWindow_drawSprite(window, rpg->lettre, NULL);
        sfRenderWindow_display(window);
    }
}
