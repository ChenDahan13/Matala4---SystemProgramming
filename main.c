#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main() {
    
    Pvertex v = NULL;
    char z = 'E';
    while (z != 'Z')
    {
       printf("Choose letter:\nA for create graph\nB to insert vertex\nD to delete vertex\nS to find shortest path\nT to TSP\nZ to stop\n");
       scanf("%c", &z);
       if(z == 'A') {
        build_graph(&v);
        print_graph(&v);
        printf("\n");
       }
       if(z == 'B') {
        insert_vertex(&v);
        print_graph(&v);
        printf("\n");
       }
       if(z == 'D') {
        delete_vertex(&v);
        print_graph(&v);
        printf("\n");
       }
       if(z == 'S') {
        int num1, num2;
        printf("Enter source vertex: ");
        scanf("%d", &num1);
        printf("Enter target vertex: ");
        scanf("%d", &num2);
        printf("%d\n", shortestPath(&v, num1, num2));
       }
       if(z == 'T'){
         TSP(&v);
       }
    }
    return 0;
}