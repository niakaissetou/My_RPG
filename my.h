/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include <unistd.h>
    #include <string.h>

typedef struct my_rpg_s {

    sfTexture* texture;
    sfSprite* sprite;

    sfTexture* text_jungle;
    sfSprite* jungle;

    sfTexture* text_button_play;
    sfSprite* button_play;

    sfTexture* text_button_setting;
    sfSprite* button_setting;

    sfTexture* text_button_exit;
    sfSprite* button_exit;

    sfTexture* text_set_menu;
    sfSprite* setting_menu;

    sfTexture* text_home_butt;
    sfSprite* home_button;

    sfTexture* text_fleche_g;
    sfSprite* fleche_gauche;

    sfTexture* text_fleche_d;
    sfSprite* fleche_droite;

    sfTexture* text_lum_plus;
    sfSprite* lum_plus;

    sfTexture* text_lum_less;
    sfSprite* lum_less;

    sfTexture* text_intro_fond;
    sfSprite* intro_fond;

    sfTexture* text_dialogue_box;
    sfSprite* dialogue_box;

    sfTexture* text_enveloppe;
    sfSprite* enveloppe;

    sfTexture* text_instruc_fond;
    sfSprite* instruc_fond;

    sfTexture* text_lettre;
    sfSprite* lettre;

    sfEvent event;

    sfFloatRect click_button_setting;
    sfFloatRect click_button_exit;
    sfFloatRect click_home;
    sfFloatRect click_button_play;
    sfFloatRect click_left;
    sfFloatRect click_right;
    sfFloatRect click_enveloppe;




    sfSprite* sprites[4];

    sfMusic* music;

    sfTexture* text_test;
    sfSprite* test;

}my_rpg;

typedef struct my_box_s {
    sfFont *font;
    sfText *file;
    sfClock* clock;
}my_box;

int my_strlen(char const *str);
void menu(my_rpg *rpg, my_box *box);
void sd_menu(my_rpg *rpg, my_box *box, sfRenderWindow* window);
void loading_menu_sprite(my_rpg *rpg);
void loading_menu_button(my_rpg *rpg);
void menu_mouse_event(my_rpg *rpg, my_box *box, sfRenderWindow* window);
void loading_setting_sprite(my_rpg *rpg);
int open_setting_menu(my_rpg *rpg, my_box *box, sfRenderWindow* window);
void principale_loop_menu(my_rpg *rpg, my_box *box, sfRenderWindow* window);
//void loading_introsprite(my_rpg *rpg);
//void loading_text(my_box *box);
void handle_close_event(my_rpg *rpg, sfRenderWindow* window);
void display_dialogue_text(const char* text, my_box* box,
sfRenderWindow* window, my_rpg *rpg);
//void handle_enveloppe_event(my_rpg *rpg, sfRenderWindow *window, my_box *box);
int play_intro(my_rpg *rpg, my_box *box, sfRenderWindow *window);
void instruction(my_rpg *rpg, sfRenderWindow* window, my_box *box);


#endif
