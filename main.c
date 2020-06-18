/*
** EPITECH PROJECT, 2019
** main
** File description:
** return
*/

#include <ncurses.h>
#include "lib/my/my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int print_map(char **str, char **save, Player_t playerp, Object_t obj)
{
    while (check_finish(str, &obj) == 1) {
        if (check_err(str) == 1) {
            refresh();
            endwin();
            my_free_array(str);
            return (1);
        }
        int gt = getch();
        str = move_left(str, &playerp, &gt, &obj);
        str = move_right(str, &playerp, &gt, &obj);
        str = move_down(str, &playerp, &gt, &obj);
        str = move_up(str, &playerp, &gt, &obj);
        str = mv_sp(str, save, &gt, &playerp, &obj);
        clear();
        my_readW(str);
        refresh();
    }
    return (0);
}

int first_check_map(char **str, char c)
{
    int index = 0;
    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == c) return (0);
        }
        index++;
    }
    return (1);
}

int p_check_map(char **str)
{
    int index = 0;
    int j = 0;
    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == 'P') j++;
        }
        index++;
    }
    if (j == 1) return (0);
    return (1);
}

int second_check_map(char **str)
{
    if (p_check_map(str) == 1) return (84);
    if (first_check_map(str, 'X') == 1) return (84);
    if (first_check_map(str, 'O') == 1) return (84);
}

int main(int argc, char **argv)
{
    Player_t playerp = {0, 0};
    Object_t obj;
    if (size_file(argv[1]) == 0) return (84);
    if (argc != 2) return (84);
    char **str = mallocstr(argv[1]);
    char **save = mallocstr(argv[1]);
    obj.x = (int *)malloc(size_file(argv[1]) * sizeof(int));
    obj.y = (int *)malloc(size_file(argv[1]) * sizeof(int));
    if (second_check_map(str) == 84) return (84);
    if (check_map(str, save) == 84) return (84);
    playerp = check_value(playerp, str, 'P');
    obj = check_0(obj, str, 'O');
    initscr();
    keypad(stdscr, TRUE);
    my_readW(str);
    if (print_map(str, save, playerp, obj) == 1) return (1);
    endwin();
    my_free_array(str);
    my_free_array(save);
    return (0);
}