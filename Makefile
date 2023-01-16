all: program main.o nodes.o edges.o graph.o

program: main.o nodes.o edges.o graph.o
	gcc -Wall -g main.o nodes.o edges.o graph.o -o program

main.o: main.c graph.h
	gcc -Wall -g -c main.c

nodes.o: nodes.c graph.h
	gcc -Wall -g -c nodes.c

edges.o: edges.c graph.h
	gcc -Wall -g -c edges.c

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c

clean: 
	rm *o program