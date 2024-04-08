/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-naira.awadin
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
