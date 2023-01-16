#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create a new edge with his direction and weight
Edge* newEdge(Vertex *endpoint, int weight)
{
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->endpoint = endpoint;
    e->weight = weight;
    e->next = NULL;
    return e;
}

// Put an edge in the end of the list
void insertLastEdge(Edge *head, Vertex *endpoint, int weight)
{
    if (head == NULL)
        return;
    Edge *e = head;
    while (e->next != NULL)
    {
        e = e->next;
    }
    e->next = newEdge(endpoint, weight);
}

// Release the edge address from memory
void deleteEdges(Pedge* edge) {
    Pedge temp = *edge;
    while (temp != NULL) {
        Pedge next = temp->next;
        free(temp);
        temp = next;
    }
    *edge = NULL;
}


// Delete specific edge from the list
void deleteSpecificEdge(Pvertex endpoint, Pedge* head) {
    if(!*head) return;
    Pedge e = *head;
    Pedge* prev = head;
    while (e) {
        if(e->endpoint == endpoint) {
            *prev = e->next;
            free(e);
            e = *prev;
        } else {
            prev = &(e->next);
            e = e->next;
        }
    }
    
}