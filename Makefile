##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.cpp)

NAME	=	hashCode

all:	$(NAME)

$(NAME): $(SRC)
	g++ -g -o $(NAME) $(SRC)

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re:	fclean all