/*
** EPITECH PROJECT, 2019
** _MY_H_
** File description:
** return
*/

#ifndef _MY_H_
#define _MY_H_

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_getnbr(char const *str);
char **mallocstr(char *files);
int size_file(char *files);
char **my_readW(char **str);
char *my_malloc(int len);
char **my_str_to_word_array(char const *str, char c);
char **malloc_array(char **word_array, char const *str, char c);
int space(char const *str, char c);
int my_super_strlen(char const *str);
void my_free_array(char **str);
int number_o(char **str, char c);
int check_map(char **str, char **save);
int first_check_map(char **str, char c);
int second_check_map(char **str);

typedef struct Player_s
{
    int x;
    int y;
} Player_t;

typedef struct Object_s
{
    int *x;
    int *y;
} Object_t;

Player_t check_value(Player_t player, char **str, char c);
char **move_left(char **str, Player_t *player, int *gt, Object_t *obj);
char **move_up(char **str, Player_t *player, int *gt, Object_t *obj);
char **move_down(char **str, Player_t *player, int *gt, Object_t *obj);
char **move_right(char **str, Player_t *player, int *gt, Object_t *obj);

Object_t check_0(Object_t obj, char **str, char c);
int check_finish(char **str, Object_t *obj);
int check_err(char **str);
char **mv_sp(char **str, char **save, int *gt, \
Player_t *playerp, Object_t *obj);
int print_map(char **str, char **save, Player_t playerp, Object_t obj);

#endif
