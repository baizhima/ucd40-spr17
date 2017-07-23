CC=clang++
CFLAGS=-std=c++14 -pedantic-errors -g -Wall
OBJS=p0_main.o Library.o Record.o Collection.o Catalog.o 

p0.out: $(OBJS)
	$(CC) -o p0.out -Wall -g $(OBJS)

p0_main.o: p0_main.cpp Record.h Catalog.h Library.h Collection.h
	$(CC) -c $(CFLAGS) p0_main.cpp

Record.o: Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp 

Library.o: Library.cpp Library.h Record.h
	$(CC) -c $(CFLAGS) Library.cpp 

Collection.o: Collection.cpp Collection.h
	$(CC) -c $(CFLAGS) Collection.cpp

Catalog.o: Catalog.cpp Catalog.h
	$(CC) -c $(CFLAGS) Catalog.cpp 

clean:
	rm -f $(OBJS) p0.out