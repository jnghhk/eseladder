.PHONY:clean

main: main.c
	gcc -o main -L../ -lfuncs -I../main.c
libfuncs.a:verticalset.o horizonset.o printline.o sound.o start.o
	ar rv libfuncs.a verticalset.o horizonset.o printline.o sound.o start.o
verticalset.o: verticalset.c
	gcc -c -g verticalset.c -o verticalset.o
horizonset.o: horizonset.c
	gcc -c -g horizonset.c -o horizonset.o
printline.o: printline.c
	gcc -c -g printline.c -o printline.o
sound.o: sound.c
	gcc -c -g sound.c -o sound.o
start.o: start.c
	gcc -c -g start.c -o start.o
clean:
	rm *.o main