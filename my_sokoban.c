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

int size_file(char *files)
{
    struct stat d_file;

    stat(files, &d_file);
    return (d_file.st_size);
}

char **mallocstr(char *files)
{
    int fd = open(files, O_RDONLY);
    int size = size_file(files);
    char **str = NULL;
    char *buf = my_malloc(size + 2);
    read(fd, buf, size);
    str = my_str_to_word_array(buf, '\n');
    close(fd);
    free(buf);

    return (str);
}

char **my_readW(char **str)
{
    int index = 0;

    while (str[index] != NULL) {
        printw(str[index]);
        printw("\n");
        index++;
    }
}

int check_map(char **str, char **save)
{
    int index = 0;
    if (number_o(str, 'O') != number_o(str, 'X')) {
        my_free_array(str);
        my_free_array(save);
        return (84);
    }
    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] ; i++) {
            if (str[index][i] != '#' && str[index][i] != 'X' && \
                str[index][i] != 'O' && str[index][i] != ' ' && \
                str[index][i] != '\n' && str[index][i] != 'P') {
                my_free_array(str);
                my_free_array(save);
                return (84);
                }
        }
        index++;
    }
    return (0);
}

int number_o(char **str, char c)
{
    int index = 0;
    int j = 0;

    while (str[index] != NULL) {
        for (int i = 0 ; str[index][i] != '\0' ; i++) {
            if (str[index][i] == c) j++;
        }
        index++;
    }
    return (j);
}