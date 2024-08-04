.PHONY: all run clean

%.o:
	gcc -c ./src/animal.c -o ./obj/animal.o -I./inc
	gcc -c ./src/main.c -o ./obj/main.o -I./inc

all: ./obj/animal.o ./obj/main.o
	gcc -o ./out/out.exe $^

run: 
	./out/out.exe

clean:
	rm obj/*.o ./out/out.exe ./out/output.txt