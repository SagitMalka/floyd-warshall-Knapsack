all: my_graph my_Knapsack
.PHONY: all clean
FLAG = -Wall -g

my_Knapsack: my_Knapsack.c
	gcc $(FLAG) my_Knapsack.c -o my_Knapsack

my_graph: mylib.a
	gcc $(FLAG) my_graph.o my_mat.o -o my_graph

mylib.a: my_graph.o my_mat.o
	ar -rcs mylib.a my_graph.o my_mat.o

my_graph.o: my_graph.c my_mat.h
	gcc $(FLAG) -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	gcc $(FLAG) -c my_mat.c


clean:
	rm -f *.o my_graph my_Knapsack *.a