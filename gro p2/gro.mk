a.exe: gro.o functions.o
	gcc gro.o functions.o

gro.o: gro.c header.h
	gcc -c gro.c

functions.o: functions.c header.h
	gcc -c functions.c
