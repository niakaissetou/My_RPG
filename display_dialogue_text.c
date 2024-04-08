/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** loading_introsprites
*/

#include "my.h"

void handle_close_event(my_rpg *rpg, sfRenderWindow* window)
{
    while (sfRenderWindow_pollEvent(window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void display_text_update(sfRenderWindow* window, my_box* box,
char* text, int* i)
{
    if (*i < my_strlen(text) && sfTime_asMilliseconds(sfClock_getElapsedTime
    (box->clock)) >= 100) {
        char* display_text = malloc(sizeof(char*) * (*i + 2));
        for (int j = 0; j <= *i; j++) {
            display_text[j] = text[j];
        }
        display_text[*i + 1] = '\0';
        sfText_setString(box->file, display_text);
        sfClock_restart(box->clock);
        (*i)++;
        free(display_text);
    }
}

void draw_dialogue_box(my_box* box, sfRenderWindow* window, my_rpg* rpg)
{
    sfRenderWindow_drawSprite(window, rpg->intro_fond, NULL);
    sfRenderWindow_drawSprite(window, rpg->dialogue_box, NULL);
    sfRenderWindow_drawSprite(window, rpg->enveloppe, NULL);
    sfRenderWindow_drawText(window, box->file, NULL);
    sfRenderWindow_display(window);
}

void display_dialogue_text(const char* text, my_box* box,
sfRenderWindow* window, my_rpg* rpg)
{
    int i = 0;
    while (sfRenderWindow_isOpen(window) && i < my_strlen(text)) {
        handle_close_event(rpg, window);
        display_text_update(window, box, (char*)text, &i);
        draw_dialogue_box(box, window, rpg);
    }
}
