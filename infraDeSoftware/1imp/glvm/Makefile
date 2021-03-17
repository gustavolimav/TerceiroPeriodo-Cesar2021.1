CC = gcc
objects = tensor_glvm.o fun.o
out = tensor_glvm.out
mult: $(objects)
	$(CC) -o tensor $(objects)

callback.o: fun.h

fun.o:

clean:
	rm $(objects) tensor

cleanAll:
	rm $(objects) $(out) tensor