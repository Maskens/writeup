CC = gcc
OBJ = main.o src/init.o
LIB = -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_ttf

write: $(OBJ)
	$(CC) -o bin/write $(OBJ) $(LIB)
main.o: main.c
	$(CC) -c main.c
init.o: init.c
	$(CC) -c src/init.c

clean:
	rm $(OBJ)
