CC = gcc-10
objects = callback.o fun.o
cb: $(objects)
	$(CC) -o cb $(objects)

callback.o: fun.h

fun.o:

clean:
	rm $(objects) cb

#use make to compile in terminator