#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedNode{
    int index;
    struct LinkedNode* next;
}Node;
typedef struct Queue{
    int front;
    int rear;
    int *data;
    int MaxSize;
}Queue;
typedef struct Graph{
    char* weight;
    Node** next;
    int size;
}Graph;
Queue* initQueue(int MaxSize){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * MaxSize);
    q->MaxSize = MaxSize;
    q->front = q->rear = 0;
    return q;
}

int isFull(Queue* q) {
    return (q->rear + 1) % q->MaxSize == q->front;
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
void enQueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("full\n");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->MaxSize;
}
int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("empty\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = ( q->front+1 ) % q->MaxSize; 
    return data;
}
// 申请内存
Graph* initGraph(int size) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->weight = (char*)malloc(sizeof(char) * size);
    G->next = (Node**)malloc(sizeof(Node*) * size);
    for (int i=0;i<size;i++) {
        G->next[i] = NULL;
    }
    G->size = size;
    return G;
}
void createGraph(Graph* G, char* weight, int* arcs) {
    for (int i=0;i<G->size;i++){
        G->weight[i] = weight[i];
        for (int j=0;j<G->size;j++){
            if (*(arcs+i*G->size+j) != 0){
                Node* node = (Node*)malloc(sizeof(Node));
                node->index = j;
                node->next = G->next[i];
                G->next[i] = node;
            }
        }
    }
}
void DFS(Graph *G, int index, int* visited) {
    printf("%c ", G->weight[index]);
    visited[index] = 1;
    Node* node = G->next[index];
    for (;node != NULL ; node = node->next) {
        if (!visited[node->index]) {
            DFS(G, node->index, visited);
        }
    }
}
void BFS(Graph* G, int index, int* visited){
    Queue* q = initQueue(5);
    printf("%c ", G->weight[index]);
    enQueue(q, index);
    visited[index] = 1;
    while (!isEmpty(q)) {
        int i = deQueue(q);
        Node* node = G->next[i];
        for (;node != NULL;node = node->next) {
            if (!visited[node->index]) {
                printf("%c ",G->weight[node->index]);
                visited[node->index] = 1;
                enQueue(q, node->index);
            }
        }  
    }
}
int main(){
    int arcs[5][5] = {
        0, 1, 1, 1, 0,
        1, 0, 1, 1, 1,
        1, 1, 0, 0, 0,
        1, 1, 0, 0, 1,
        0, 1, 0, 1, 0};
    Graph* G = initGraph(5);
    createGraph(G, "ABCDE", (int*)arcs);
    int *visited = (int*)malloc(sizeof(int) * G->size);
    for (int i=0;i<G->size;i++)
        visited[i] = 0;
    // BFS(G, 0, visited);
    DFS(G, 0, visited);
}