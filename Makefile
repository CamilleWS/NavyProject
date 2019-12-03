##
## EPITECH PROJECT, 2017
## navy
## File description:
## Makefile
##

SRC	=	src/get_next_line.c	\
		src/printing_map.c	\
		src/check_pos.c	\
		src/update.c	\
		src/navy.c		\
		src/boat.c		\
		src/lib.c		\
		src/inits.c		\
		src/help.c		\
		src/phases.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

NAME	=	navy

CC	=	gcc

$(NAME):	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(FLAGS) -I./include/ -g3

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
