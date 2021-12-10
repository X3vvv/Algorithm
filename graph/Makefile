main: main.o utils.o
	gcc -g -o main main.o utils.o

main.o: main.c
	gcc -c main.c

utils.o: utils.c
	gcc -c utils.c

clean:
	del main.exe main.o utils.o
	
.PHONY: main clean