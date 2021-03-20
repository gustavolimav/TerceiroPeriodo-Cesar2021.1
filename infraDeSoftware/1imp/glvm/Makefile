CC = gcc
objects = aulaYT.o fun.o
#objects = tensor_glvm.o fun.o
out = aulaYT.out
mult: $(objects)
	$(CC) -o tensor $(objects) -lrt

callback.o: fun.h

fun.o:

clean:
	rm $(objects) tensor

cleanAll:
	rm $(objects) $(out) tensor