#include <stdio.h>
#include <stdlib.h>

// -------- STRUCTURES --------

// Node of adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;   // Array of linked lists
    int* visited;
} Graph;


// -------- QUEUE FOR BFS --------

typedef struct Queue {
    int items[100];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return (q->rear == -1);
}

void enqueue(Queue* q, int value) {
    if (q->rear == 99) return;

    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;

    if (isEmpty(q)) return -1;

    item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}


// -------- GRAPH FUNCTIONS --------

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    // Add edge src -> dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge dest -> src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


// -------- DFS --------

void DFS(Graph* graph, int vertex) {
    Node* temp = graph->adjLists[vertex];

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}


// -------- BFS --------

void BFS(Graph* graph, int startVertex) {
    Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}


// -------- MAIN FUNCTION --------

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("DFS Traversal: ");
    DFS(graph, 0);

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++)
        graph->visited[i] = 0;

    printf("\nBFS Traversal: ");
    BFS(graph, 0);

    return 0;
}
