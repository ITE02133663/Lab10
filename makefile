all: server client

client: client.o
	gcc -o client client.o

server: server.o doprocessing.o
	gcc -o server server.o doprocessing.o

doprocessing.o:	doprocessing.c
	gcc -c doprocessing.c

clean:
	/bin/rm -rf *.o
