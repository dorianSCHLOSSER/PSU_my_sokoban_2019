/*
** EPITECH PROJECT, 2019
** movement_map
** File description:
** return
*/

#include <ncurses.h>
#include "lib/my/my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char **move_left(char **str, Player_t *player, int *gt, Object_t *obj)
{
    if (*gt == KEY_LEFT) {
        str[player->y][player->x] = ' ';
        for (int i = 0 ; i < number_o(str, 'X') + 1 ; i++) {
            if (player->x == obj->x[i] && player->y == obj->y[i])
            str[player->y][player->x] = 'O';
        }
        (str[player->y][player->x - 1] == '#') ? player->x += 1 : 0;
        (str[player->y][player->x - 1] == 'X' && \
        str[player->y][player->x - 2] == '#') ? player->x += 1 : 0;
        (str[player->y][player->x - 1] == 'X' && \
        str[player->y][player->x - 2] == 'X') ? player->x += 1 : 0;
        if (str[player->y][player->x - 1] == 'X' && \
            str[player->y][player->x - 2] != '#') {
            str[player->y][player->x - 2] = 'X';
        }
        player->x -= 1;
        str[player->y][player->x] = 'P';
    }
    return (str);
}

char **move_right(char **str, Player_t *player, int *gt, Object_t *obj)
{
    if (*gt == KEY_RIGHT) {
        str[player->y][player->x] = ' ';
        for (int i = 0 ; i < number_o(str, 'X') + 1 ; i++) {
            if (player->x == obj->x[i] && player->y == obj->y[i])
                str[player->y][player->x] = 'O';
        }
        (str[player->y][player->x + 1] == '#') ? player->x -= 1 : 0;
        (str[player->y][player->x + 1] == 'X' && \
        str[player->y][player->x + 2] == '#') ? player->x -= 1 : 0;
        (str[player->y][player->x + 1] == 'X' && \
        str[player->y][player->x + 2] == 'X') ? player->x -= 1 : 0;
        if (str[player->y][player->x + 1] == 'X' && \
            str[player->y][player->x + 2] != '#') {
            str[player->y][player->x + 2] = 'X';
        }
        player->x += 1;
        str[player->y][player->x] = 'P';
    }
    return (str);
}

char **move_down(char **str, Player_t *player, int *gt, Object_t *obj)
{
    if (*gt == KEY_DOWN) {
        str[player->y][player->x] = ' ';
        for (int i = 0 ; i < number_o(str, 'X') + 1 ; i++) {
            if (player->x == obj->x[i] && player->y == obj->y[i])
                str[player->y][player->x] = 'O';
        }
        (str[player->y + 1][player->x] == '#') ? player->y -= 1 : 0;
        (str[player->y + 1][player->x] == 'X' && \
        str[player->y + 2][player->x] == '#') ? player->y -= 1 : 0;
        (str[player->y + 1][player->x] == 'X' && \
        str[player->y + 2][player->x] == 'X') ? player->y -= 1 : 0;
        if (str[player->y + 1][player->x] == 'X' && \
            str[player->y + 2][player->x] != '#') {
            str[player->y + 2][player->x] = 'X';
        }
        player->y += 1;
        str[player->y][player->x] = 'P';
    }
    return (str);
}

char **move_up(char **str, Player_t *player, int *gt, Object_t *obj)
{
    if (*gt == KEY_UP) {
        str[player->y][player->x] = ' ';
        for (int i = 0 ; i < number_o(str, 'X') + 1 ; i++) {
            if (player->x == obj->x[i] && player->y == obj->y[i])
                str[player->y][player->x] = 'O';
        }
        (str[player->y - 1][player->x] == '#') ? player->y += 1 : 0;
        (str[player->y - 1][player->x] == 'X' && \
        str[player->y - 2][player->x] == '#') ? player->y += 1 : 0;
        (str[player->y - 1][player->x] == 'X' && \
        str[player->y - 2][player->x] == 'X') ? player->y += 1 : 0;
        if (str[player->y - 1][player->x] == 'X' && \
            str[player->y - 2][player->x] != '#') {
            str[player->y - 2][player->x] = 'X';
        }
        player->y -= 1;
        str[player->y][player->x] = 'P';
    }
    return (str);
}

char **mv_sp(char **str, char **save, int *gt, Player_t *playerp, Object_t *obj)
{
    int j = 0;

    if (*gt == 32) {
        while (save[j] != NULL) {
            for (int i = 0 ; save[j][i] != '\0' ; i++) str[j][i] = save[j][i];
            j++;
        }
        *playerp = check_value(*playerp, str, 'P');
        *obj = check_0(*obj, str, 'O');
    }
    return (str);
}
