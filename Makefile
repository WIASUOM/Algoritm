all: Algoritm


Algoritm: main.o
	gcc src/main.o -l raylib -o Algoritm.exe
	chmod +x Algoritm.exe


main.o: src/main.c
	gcc -c src/main.c -o src/main.o

clean:
	rm -rf Algoritm.exe src/main.o
