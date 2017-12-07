main: main.o
	gcc -o ladder -L../funcs main.o -lfuncs
main.o: main.c
	gcc -g -c -I../hfiles main.c -o main.o
clean:
	rm *.o ladder	
