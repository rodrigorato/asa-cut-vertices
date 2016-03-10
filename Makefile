main: main.c
	gcc -o c.out -O3 -ansi -Wall main.c -lm

cpp: main.cpp
	g++ -o cpp.out -O3 -ansi -Wall main.cpp -lm

clean:
	rm -rf *.out
