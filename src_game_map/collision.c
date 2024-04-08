/*
** EPITECH PROJECT, 2023
** collision_in_map
** File description:
** map_collision
*/
#include "my_map.h"

int handle_collision(long unsigned int x, long unsigned int y)
{
    sfImage *image = sfImage_createFromFile("font.png");
    sfColor color = sfImage_getPixel(image, x, y);

    if (color.r >= 76 && color.b >= 25) {
        return 1;
    } else
        return 0;
    sfImage_destroy(image);
}
