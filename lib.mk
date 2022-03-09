a.exe: adddelete.o borrowreturn.o client.o datfine.o menu.o searchview.o validity.o
	gcc adddelete.o borrowreturn.o client.o datfine.o menu.o searchview.o validity.o
adddelete.o: adddelete.c library.h
	gcc -c adddelete.c
borrowreturn.o: borrowreturn.c library.h
	gcc -c borrowreturn.c
client.o: client.c library.h
	gcc -c client.c
datfine.o: datfine.c library.h
	gcc -c datfine.c
menu.o: menu.c library.h
	gcc -c menu.c
searchview.o: searchview.c library.h
	gcc -c searchview.c
validity.o: validity.c library.h
	gcc -c validity.c