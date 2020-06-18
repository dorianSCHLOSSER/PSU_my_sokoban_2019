##
## EPITECH PROJECT, 2019
## makefile
## File description:
## return
##

SRC = 	main.c			\
		my_sokoban.c	\
		movement_map.c	\
		my_sokoban1.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

FLAGS =  -Llib/my -lmy

all:
	make -C lib/my build
	gcc -lncurses -g -o $(NAME) $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)
		rm -f ./lib/my/*.o
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		rm -f ./lib/*.a
		rm -f ./lib/my/*.a

re: fclean all