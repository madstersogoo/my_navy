##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

NAME =  matchstick

FILES = affichage.c		\
	error.c			\
	ia.c			\
	interface_play.c	\
	matchstique.c		\
	my_run.c		\
	playeur.c		\

all :	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

prepush:	fclean
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~
	git add --all
	git status

tree:	prepush
	tree -a -I .git

push:	prepush
	git commit -m 'auto-sync with master'
	git push origin master

pull:
	git pull origin master

sync:	pull	push

debug:
	clear
	gcc -o $(NAME) $(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system

valgrind:
	gcc -g3 -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system

update:
	../mmkfile.sh
