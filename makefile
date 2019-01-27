solution: solution.o
	gcc -o solution solution.o

solution.o: solution.c
	gcc -c -o solution.o solution.c
