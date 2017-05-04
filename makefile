all: mRun

mRun: main.o
	gcc main.o -o mRun

main.o: main.c MazeRun.h
	gcc -c main.c MazeRun.h -g -Wall 
clean:
	rm *o mRun
