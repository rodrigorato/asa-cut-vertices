main: main.c
	gcc -O3 -ansi -Wall main.c -lm

clean:
	rm -rf *.out
