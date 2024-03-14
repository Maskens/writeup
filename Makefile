CC = gcc
OBJ = main.o src/init.o src/input.o src/file.o
LIB = -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_ttf

write: $(OBJ)
	$(CC) -o bin/write $(OBJ) $(LIB)
main.o: main.c
	$(CC) -c main.c
init.o: init.c
	$(CC) -c src/init.c
input.o: input.c
	$(CC) -c src/input.c
file.o: file.c
	$(CC) -c src/file.c

clean:
	rm $(OBJ)
