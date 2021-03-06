CC = gcc
objects = mult_glvm.o fun.o
out = mult_glvm.out
mult: $(objects)
	$(CC) -o mult $(objects)

callback.o: fun.h

fun.o:

clean:
	rm $(objects) mult

cleanAll:
	rm $(objects) $(out) mult