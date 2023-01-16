#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

// Create a new vertex only with his number
Vertex* newVertex(int number) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->number = number;
    v->edge = NULL;
    v->next = NULL;
    return v;
}

// Create a new vertex with his number and edges
Vertex* newVertexEdge(int number, Edge* edge) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->number = number;
    v->edge = edge;
    v->next = NULL;
    return v;
}

// Add a vertex to the end of the list
void insertLastVertex(int number, Vertex* head) {
    if(head == NULL) return;
    Vertex* v = head;
    while (v->next != NULL) {
        v = v->next;
    }
    v->next = newVertex(number);
    
}

// Add a vertex to the end of the list
void insertLastVertexEdge(int number, Edge* edge, Vertex* head) {
    if(head == NULL) return;
    Vertex* v = head;
    while (v->next != NULL) {
        v = v->next;
    }
    v->next = newVertexEdge(number, edge);  
}

// Delete specific vertex from the list
void deleteVertex(int number, Pvertex* head) {
    if(!*head) return;
    Pvertex v = *head;
    Pvertex* prev = head;
    while (v) {
        if(v->number == number) {
            *prev = v->next;
            deleteEdges(&(v->edge));
            free(v);
            v = *prev;
        } else {
            prev = &(v->next);
            v = v->next;
        }
    }
    
}

