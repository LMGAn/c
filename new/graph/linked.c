#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int index;
    struct Node* next;
}Node;
typedef struct Graph{
    char *vexs;
    Node** next;// 指针数组
    int size; // 总大小
}Graph;
typedef struct Queue{
    int front;
    int rear;
    int *data;
    int MAXSIZE;
}Queue;
Queue* initQueue(int MaxSize){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * MaxSize);
    q->MAXSIZE = MaxSize;
    q->rear = q->front = 0;
    return q;
}
int isFull(Queue* q) {
    return (q->rear + 1) % q->MAXSIZE == q->front;
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
void enQueue(Queue* q, int index) {
    if (isFull(q))  
        return;
    q->data[q->rear] = index;
    q->rear = ( q->rear+1 ) %q->MAXSIZE;
}
int deQueue(Queue* q) {
    if(isEmpty(q))
        return -1;
    int index = q->data[q->front];
    q->front = ( q->front+1 ) % q->MAXSIZE;
    return index;
}
Graph* initGraph(int size) {
    Graph* G= (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char) * size);
    G->next = (Node**)malloc(sizeof(Node*)*size);
    for (int i=0;i<size;i++){  
        G->next[i] = NULL;
    }
    G->size = size;
    return G;
}
void createGraph(Graph* G, char* vexs, int* arcs){
    for (int i=0;i<G->size;i++) {
        G->vexs[i] = vexs[i];
        for (int j=0;j<G->size;j++){
            if (*(arcs+i*G->size + j) != 0) {
                Node* node = (Node*)malloc(sizeof(Node));
                node->index = j;
                node->next = G->next[i];
                G->next[i] = node;
            }
        }
    }
}
void DFS(Graph* G, int* visited, int index) {
    visited[index] = 1;
    printf("%c ", G->vexs[index]);
    Node *node = G->next[index];
    for (; node != NULL; node = node->next) {
        if (!visited[node->index]) {
            DFS(G, visited, node->index);
        }
    }
}
int isIn(Queue* q, int index) {
    for (int i=q->front ; i != q->rear ; i = ( i+1)%q->MAXSIZE )
        if (q->data[i] == index)
            return 1;
    return 0;
}
void BFS(Graph* G, int* visited, int index) {
    Queue* q = initQueue(G->size);
    enQueue(q, index);
    while (!isEmpty(q)){
        int i = deQueue(q);
        printf("%c ", G->vexs[i]);
        visited[i] = 1;
        for (Node* node = G->next[i];node != NULL ;node = node->next)
            if (!visited[node->index] && !isIn(q, node->index))
                enQueue(q, node->index);
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
    BFS(G, visited, 0);
}