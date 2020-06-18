/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** return
*/

#include <stdlib.h>
#include "my.h"

char *my_malloc(int len)
{
    int i = 0;
    char *result = NULL;

    result = malloc(sizeof(char) * len);
    for (; i < len ; i++) result[i] = 0;

    return (result);
}