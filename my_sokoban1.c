/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** return
*/

#include <ncurses.h>
#include "lib/my/my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

Player_t check_value(Player_t player, char **str, char c)
{
    int index = 0;

    Player_t element = {0, 0};

    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == c) return (element);
            element.x += 1;
        }
        index += 1;
        element.x = 0;
        element.y += 1;
    }
}

Object_t check_0(Object_t obj, char **str, char c)
{
    int index = 0;
    int j = 0;

    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == c) {
                j++;
                obj.x[j] = obj.x[j - 1];
                obj.y[j] = obj.y[j - 1];
            }
            obj.x[j] += 1;
        }
        index += 1;
        obj.x[j] = 0;
        obj.y[j] = index - 1;
        obj.y[j] += 1;
    }
    return (obj);
}

int check_finish(char **str, Object_t *obj)
{
    int index = 0;
    int j = 0;

    for (int i = 0 ; i < number_o(str, 'X') ; i++) {
        if (str[obj->y[j]][obj->x[j]] == 'X')
        j++;
        if (j == number_o(str, 'O') + 1) return (0);
        else return (1);
    }
    return (0);
}

int check_err(char **str)
{
    int index = 0;
    int j = 0;
    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == 'X' && ((str[index][i - 1] == '#' || \
            str[index][i - 1] == 'X') && (str[index - 1][i] == '#' || \
            str[index - 1][i] == 'X'))) j++;
            if (str[index][i] == 'X' && ((str[index][i + 1] == '#' || \
            str[index][i + 1] == 'X') && (str[index + 1][i] == '#' || \
            str[index + 1][i] == 'X'))) j++;
            if (str[index][i] == 'X' && ((str[index][i + 1] == '#' || \
            str[index][i + 1] == 'X') && (str[index - 1][i] == '#' || \
            str[index - 1][i] == 'X'))) j++;
            if (str[index][i] == 'X' && ((str[index][i - 1] == '#' || \
            str[index][i - 1] == 'X') && (str[index + 1][i] == '#' || \
            str[index + 1][i] == 'X'))) j++;
        } index += 1;
    }
    if (j >= number_o(str, 'X')) return (1);
    return (0);
}