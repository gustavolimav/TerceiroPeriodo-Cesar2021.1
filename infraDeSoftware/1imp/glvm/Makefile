CC = gcc
#objects = aulaYT.o fun.o
objects = tensor_glvm.o fun.o
out = tensor_glvm.out
mult: $(objects)
	$(CC) -o tensor $(objects) -lrt -pthread

tensor_glvm.o: fun.h tensor_glvm.c
	$(CC) -c -o tensor_glvm.o tensor_glvm.c -lrt -pthread 

fun.o: fun.h

clean:
	rm $(objects) tensor

cleanAll:
	rm $(objects) $(out) tensor