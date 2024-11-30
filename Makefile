all: Algoritm


Algoritm: main.o
	gcc src/main.o -l raylib -o Algoritm.exe
	chmod +x Algoritm.exe


main.o: src/main.cpp
	gcc -c src/main.cpp -o src/main.o

clean:
	rm -rf Algoritm.exe src/main.o
