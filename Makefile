##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

INCLUDE		=		-I./include/

SRC 		=		$(shell find -name *.c)

NAME		=		amazed

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -g -o $(NAME) $(SRC) $(INCLUDE)

clean :
	rm -f vgcore*
	rm -f coding-style-reports.log

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
