/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** play_intro
*/

#include "my.h"

void loading_introsprite(my_rpg *rpg)
{
    rpg->text_intro_fond = sfTexture_createFromFile("img/jungle.gif", NULL);
    rpg->intro_fond = sfSprite_create();
    sfSprite_setTexture(rpg->intro_fond, rpg->text_intro_fond, sfTrue);

    rpg->text_dialogue_box = sfTexture_createFromFile("img/d_box.png", NULL);
    rpg->dialogue_box = sfSprite_create();
    sfSprite_setTexture(rpg->dialogue_box, rpg->text_dialogue_box, sfTrue);
    sfSprite_setPosition(rpg->dialogue_box, (sfVector2f){280, 600});
    sfSprite_setScale(rpg->dialogue_box, (sfVector2f){3.0f, 2.0f});

    rpg->text_enveloppe = sfTexture_createFromFile("img/enveloppe.png", NULL);
    rpg->enveloppe = sfSprite_create();
    sfSprite_setTexture(rpg->enveloppe, rpg->text_enveloppe, sfTrue);
    sfSprite_setPosition(rpg->enveloppe, (sfVector2f){1390, 720});
}

void loading_text(my_box *box)
{
    box->font = sfFont_createFromFile("texture/arrial.ttf");
    box->file = sfText_create();
    sfText_setFont(box->file, box->font);
    sfText_setCharacterSize(box->file, 20);
    sfText_setFillColor(box->file, sfBlack);
    sfText_setPosition(box->file, (sfVector2f){400, 650});
}

void handle_enveloppe_event(my_rpg *rpg, sfRenderWindow *window, my_box *box)
{
    while (sfRenderWindow_pollEvent(window, &rpg->event)) {
            rpg->click_enveloppe = sfSprite_getGlobalBounds(rpg->enveloppe);
                if (sfFloatRect_contains(&rpg->click_enveloppe,
                rpg->event.mouseButton.x, rpg->event.mouseButton.y)) {
                    instruction(rpg, window, box);
                }
        }
}

int play_intro(my_rpg *rpg, my_box *box, sfRenderWindow* window)
{
    loading_introsprite(rpg);
    loading_text(box);
    const char* texts[] = {"Oh! Si tu es la, c'est que tu peux m'aider!",
                        "Bienvenue dans le monde de l'aventure!",
                        "Je suis l'esprit de la jungle et j'ai besoin de toi.",
                        "Clique sur cette enveloppe vite!"};
    box->clock = sfClock_create();
    for (int i = 0; i < 4; i++) {
        display_dialogue_text(texts[i], box, window, rpg);
    }
    while (sfRenderWindow_isOpen(window)) {
        handle_enveloppe_event(rpg, window, box);
    }
    return 0;
}
