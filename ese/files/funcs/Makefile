libfuncs.a: mapset.o start.o
	ar rv libfuncs.a mapset.o start.o
%.o: %.c
	gcc -g -Wall -c $< -o $@
clean:
	rm *.o *.a
