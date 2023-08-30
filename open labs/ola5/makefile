CC=c++
CFLAGS=-I.

inventory1: inventory1.o 
	$(CC) $(CFLAGS) inventory1.o -o inventory1

inventory1.o: inventory1.cpp
	$(CC) $(CFLAGS) -c inventory1.cpp

clean:
	rm *.o 
