#ifndef GRAPH_H
#define GRAPH_H

typedef struct Vertex *Pvertex;;

typedef struct Edge {
    int weight;
    Pvertex endpoint;
    struct Edge* next;
} Edge, *Pedge;


typedef struct Vertex {
    int number;
    Pedge edge;
    struct Vertex* next;  

} Vertex, *Pvertex;


//---------edges.c---------
Edge* newEdge(Vertex*, int);
void insertLastEdge(Pedge, Vertex*, int);
void deleteEdges(Pedge*);
void deleteSpecificEdge(Pvertex, Pedge*);
//-------------------------


//---------nodes.c---------
Vertex* newVertex(int);
Vertex* newVertexEdge(int, Edge*);
void insertLastVertex(int, Vertex*);
void insertLastVertexEdge(int, Edge*, Vertex*);
void deleteVertex(int, Vertex**);
//-------------------------


//--------graph.c----------
void build_graph(Pvertex*);
Pvertex findVertex(Pvertex*, int);
void insert_vertex(Pvertex*);
void delete_vertex(Pvertex*);
void delete_graph(Pvertex*);
void print_graph(Pvertex*);
int shortestPath(Pvertex*, int, int);
int graphMaxNumber(Pvertex*);
int findMinIndexInArray(int*,int* ,int);
int checkIfArrayEmpty(int*, int);
void TSP(Pvertex*);
void swap(int*, int*);
void permute(int*, int, int, int**, int*);
//-------------------------

#endif 