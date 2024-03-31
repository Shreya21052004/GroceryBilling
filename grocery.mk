a.exe: billmain.o grocery.o
	gcc main.o grocery.o

billmain.o: billmain.c grocery.h
	gcc -c billmain.c

grocery.o: grocery.c grocery.h
	gcc -c grocery.c