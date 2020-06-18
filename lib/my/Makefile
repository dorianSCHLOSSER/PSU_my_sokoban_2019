##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## return
##

SRC =	my_strlen.c				\
		my_putstr.c				\
		my_str_to_word_array.c	\
		my_free_array.c			\
		my_malloc.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

HEADER  = 	my.h

build:
	gcc -c -g $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/