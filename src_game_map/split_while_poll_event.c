/*
** EPITECH PROJECT, 2023
** while_poll_event
** File description:
** pollçevent
*/
#include "my_map.h"

void cond_key_l_r(my_rpg *rpg, sfView *view, anime_t *anim)
{
    sfVector2f move_r = {3, 0};
    sfVector2f move_l = {-3, 0};

    if (rpg->event.key.code == sfKeyRight) {
        if (handle_collision(anim->pos.x + 20, anim->pos.y) == 0)
            return;
        if (handle_collision(anim->pos.x + 20, anim->pos.y - 25) == 0)
            return;
        sfView_move(view, move_r);
        anim->pos_livre.x += 3;
        anim->pos.x += 3;
    }
    if (rpg->event.key.code == sfKeyLeft) {
        if (handle_collision(anim->pos.x, anim->pos.y) == 0)
            return;
        if (handle_collision(anim->pos.x, anim->pos.y - 25) == 0)
            return;
        sfView_move(view, move_l);
        anim->pos_livre.x -= 3; anim->pos.x -= 3;
    }
}

void cond_key_u_d(my_rpg *rpg, sfView *view, anime_t *anim)
{
    sfVector2f move_u = {0, -3};
    sfVector2f move_d = {0, 3};

    if (rpg->event.key.code == sfKeyUp) {
        if (handle_collision(anim->pos.x + 20, anim->pos.y - 25) == 0)
            return;
        if (handle_collision(anim->pos.x + 2, anim->pos.y - 25) == 0)
            return;
        sfView_move(view, move_u);
        anim->pos_livre.y -= 3;
        anim->pos.y -= 3;
    }
    if (rpg->event.key.code == sfKeyDown) {
        if (handle_collision(anim->pos.x, anim->pos.y) == 0)
            return;
        if (handle_collision(anim->pos.x + 20, anim->pos.y) == 0)
            return;
        sfView_move(view, move_d);
        anim->pos_livre.y += 3; anim->pos.y += 3;
    }
}

int while_for_display(sfRenderWindow *w, my_rpg *rpg, sfView *v, anime_t *a)
{
    while (sfRenderWindow_pollEvent(w, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(w);
        }
        cond_key_l_r(rpg, v, a);
        cond_key_u_d(rpg, v, a);
        return 0;
    }
}
