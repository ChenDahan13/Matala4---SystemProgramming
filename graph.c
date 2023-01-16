#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

// Returns the biggest vertex number
int graphMaxNumber(Pvertex* head) {
    int max = 0;
    Pvertex v = *head;
    while (v)
    {
        if(max < v->number) 
            max = v->number;
        v = v->next;
    }
    return max;
}


// Searches vertex in the graph and returns it
Pvertex findVertex(Pvertex* head, int number)
{
    Pvertex v = *head;
    while ((v != NULL) && (v->number != number))
    {
        v = v->next;
    }
    return v;
}

// Creates graph
void build_graph(Pvertex *head)
{
    if (*head != NULL) {
        delete_graph(head);
    }

    int n = 0;
    printf("Enter number of vertexes: ");
    scanf("%d", &n);
    // Check right input
    if (n <= 0)
        return;

    // Create only vertexes
    *head = newVertex(0);
    int i;
    for (i = 1; i < n; i++)
    {
        insertLastVertex(i, *head);
    }

    Pvertex v1 = NULL;
    Pvertex v2 = NULL;
    
    char x;
    printf("Enter n for vertex: ");
    scanf(" %c", &x);
    // Check right input
    if (x != 'n') return;
    
    for (i = 0; i < n; i++)
    {
        if (x == 'n')
        {
            printf("Enter vertex: ");
            scanf(" %c", &x);
            // Check right input
            if (x < '0' || x > '9') return;
            
            x = x - '0';
            v1 = findVertex(head, x);
            // Check exist
            if(v1 == NULL) return;
            printf("Enter endpoint Vertex: ");
            scanf(" %c", &x);
            // Check right input
            if (x < '0' || x > '9') return;
            
        }
        while (x != 'n')
        {
            if (v1->edge == NULL)
            {
                x = x - '0';
                v2 = findVertex(head, x);
                // Check exist
                if(v2 == NULL) return;
                printf("Enter weight: "); 
                scanf(" %c", &x);
                // Check right input
                if (x < '0' || x > '9') return;
                
                x = x - '0';
                v1->edge = newEdge(v2, x);
            }
            else
            {
                x = x - '0';
                v2 = findVertex(head, x);
                // Check exist
                if(v2 == NULL) return;
                printf("Enter weight: ");
                scanf(" %c", &x);
                // Check right input
                if (x < '0' || x > '9') return;
                
                x = x - '0';
                insertLastEdge(v1->edge, v2, x);
            }
            printf("Enter n or endpoint vertex: ");
            scanf(" %c", &x); // 'n' to stop
            
        }
    }
    
}

// Checks if the vertex exist, if not create it
void insert_vertex(Pvertex* head) {
    int n, w;
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    Pvertex v1 = NULL;
    Pvertex v2 = NULL;
    Pedge edge = NULL;
    v1 = findVertex(head, n);
    if (v1 == NULL) // not exist in the graph
    {
        printf("Enter endpoint: ");
        scanf("%d", &w);
        if (w < 0)
            return; // Check right input
        v2 = findVertex(head, w);
        if (v2 == NULL)
            return; // Check right input
        printf("Enter weight: ");
        scanf("%d", &w);
        edge = newEdge(v2, w);
        printf("Enter if you want to continue 0, else -1");
        scanf("%d", &w);
        while (w == 0)
        {
            printf("Enter endpoint: ");
            scanf("%d", &w);
            if (w < 0)
                return; // Check right input
            v2 = findVertex(head, w);
            if (v2 == NULL)
                return; // Check right input
            printf("Enter weight: ");
            scanf("%d", &w);
            insertLastEdge(edge, v2, w);
            printf("Enter if you want to continue 0, else -1");
            scanf("%d", &w);
        }
        insertLastVertexEdge(n, edge, *head);
        } 
    else
    { 
        deleteEdges(&(v1->edge));
        printf("Enter endpoint: ");
        scanf("%d", &w);
        if (w < 0)
            return; // Check right input
        v2 = findVertex(head, w);
        if (v2 == NULL)
            return; // Check right input
        printf("Enter weight: ");
        scanf("%d", &w);
        v1->edge = newEdge(v2, w);
        printf("Enter if you want to continue 0, else -1\n");
        scanf("%d", &w);
        while (w == 0)
        {
            printf("Enter endpoint: ");
            scanf("%d", &w);
            if (w < 0)
                return; // Check right input
            v2 = findVertex(head, w);
            if (v2 == NULL)
                return; // Check right input
            printf("Enter weight: ");
            scanf("%d", &w);
            insertLastEdge(v1->edge, v2, w);
            printf("Enter if you want to continue 0, else -1\n");
            scanf("%d", &w);
        }
    }  
}

// Deletes vertex and all the edges that direct to it
void delete_vertex(Pvertex* head) {
    int n;
    printf("Enter vertex to delete: ");
    scanf("%d", &n);
    Pvertex v1 = NULL;
    v1 = findVertex(head, n);
    if(v1 == NULL) return;

    Pvertex v2 = *head;
    while (v2) {
        deleteSpecificEdge(v1, &(v2->edge));
        v2 = v2->next;
    }

    deleteVertex(n, head);  
}


void print_graph(Pvertex* head){
    Pvertex v1 = *head;
    Pedge e = NULL;
    while (v1)
    {
        printf("%d: ", v1->number);
        e = v1->edge;
        while (e)
        {
            printf("\n  --%d--> %d ", e->weight, e->endpoint->number);
            e = e->next;
        }
        printf("\n\n");
        v1 = v1->next;
    } 
}


// Releases the vertexes addresses from memory
void delete_graph(Pvertex* head) {
    Pvertex temp = *head;
    while (temp != NULL) {
        Pvertex next = temp->next;
        deleteEdges(&(temp->edge));
        free(temp);
        temp = next;
    }
    *head = NULL;
}



// Finds minimum value index in array
int findMinIndexInArray(int* dis, int* wasVisit, int len) {
    int min = __INT_MAX__;
    int index = -1;
    int i;
    for(i = 0; i < len; i++) {
        if((dis[i] < min) && (wasVisit[i] != 1)) {
            min = dis[i];
            index = i;
        }
    }
    return index;
}

// Checks if all the vertexes were visited
// Instead of a queue i use array, value 1 if was visited, 0 if not 
int checkIfArrayEmpty(int* arr, int len) {
    int check = 1;
    int i;
    for (i = 0; i < len; i++) {
        if(arr[i] == 0) 
            check = 0;
    }
    return check;
}

// Finds the sortest paths from one vertex to others with Dijkstra's algorithm 
int shortestPath(Pvertex* head, int num1, int num2) {
    // Checks if the vertexes exist
    if(findVertex(head,num1) == NULL || findVertex(head, num2) == NULL)
        return -1; // No exist vertex
    
    
    int len = graphMaxNumber(head) + 1;
    
    int dis[len];
    int wasVisit[len];
    int i;

    // Initial all
    for (i = 0; i < len; i++)
    {
        dis[i] = __INT_MAX__;
        wasVisit[i] = 1;
    }
    
    Pvertex v = *head;
    
    // to know which vertexes are in the graph 
    while (v)
    {
        wasVisit[v->number] = 0;
        v = v->next;
    }
    

    dis[num1] = 0;
    int index;

    // Pointers
    v = NULL;
    Pedge e = NULL;

    while (!(checkIfArrayEmpty(wasVisit, len)))
    {
        index = findMinIndexInArray(dis, wasVisit, len);
        
        if (index == -1) break; // all the vertexes were visited
        wasVisit[index] = 1;

        v = findVertex(head, index);
        e = v->edge;
        while (e)
        {
            if (dis[e->endpoint->number] > dis[v->number] + e->weight)
                dis[e->endpoint->number] = dis[v->number] + e->weight;
            
            e = e->next;
        }
    }

    if(dis[num2] == __INT_MAX__)
        return -1;
    else
        return dis[num2];
}

// Calculates the factorial of the number
int factorial(int num) {
    int count = 1;
    int i;
    for(i=1;i<=num;i++)
        count = count*i;
    
    return count;
}


// Creates all optional permutations and puts it in matrix
void permute(int* arr, int l, int r, int** mat, int *numlines) {
    int i;
    if(l==r) {
        for (i = 0; i <= r; i++)
        {
            mat[*numlines][i] = arr[i];
        }
        *numlines = *numlines + 1;
    }
    else {
        for(i=l; i <= r; i++){
            swap(arr+l, arr+i);
            permute(arr, l+1, r, mat, numlines);
            swap(arr+l, arr+i);
        }
    }
}


void swap(int* x, int* y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

// Gets number of vertexes and finds the shortest path between them
// The order of the vertexes doesn't matter
void TSP(Pvertex* head) {
    int numofVertexes;
    printf("Enter amount of vertexes: ");
    scanf("%d", &numofVertexes);
    int *arr = (int*)malloc(numofVertexes*(sizeof(int)));
    int i, j;
    
    // puts the chosen vertexes in array
    for (i = 0; i < numofVertexes; i++)
    {
        printf("Enter vertex: ");
        scanf("%d", arr + i);
    }
    
    // Creates available matrix to all the options
    int numFact = factorial(numofVertexes);
    int **mat = (int**)malloc(numFact*sizeof(int*));
    for(i=0;i<numFact;i++) {
        mat[i] = (int*)malloc(numofVertexes*sizeof(int));
    }

    int numlines = 0;
    // Create the matrix
    permute(arr, 0, numofVertexes - 1, mat, &numlines);
    int count = 0;
    int ifNoPath = 1;
    int minDis = __INT_MAX__;
    // Checking all the paths
    for (i = 0; i < numFact; i++)
    {
        for (j = 0; j <  numofVertexes - 1; j++)
        {
            if(shortestPath(head, mat[i][j], mat[i][j+1]) == -1){
                // No path, get out from the loop
                j = numofVertexes; 
                ifNoPath = 0;
            }
            else
            {
                count = count + shortestPath(head, mat[i][j], mat[i][j+1]);
            }
        }

        // Check the shortest only if there is path
        if (ifNoPath)
        {
            if (count<minDis)
                minDis = count;
            count = 0;
        }
        else {
            ifNoPath = 1;  
            count = 0;
        }

    }
    
    if(minDis == __INT_MAX__)
        printf("-1\n");
    else
        printf("The shortest path between all the vertexes is: %d\n", minDis);



    for(i=0;i<numFact;i++) {
        free(mat[i]);
    }
    free(mat);
    free(arr);
}