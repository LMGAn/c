#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct Graph{
    char *vexs;
    int vexNum;
    int arcNum;
    int **arcs;
}Graph;
typedef struct Queue{
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->rear = q->front = 0;
    return q;
}
int isEmpty(Queue* q) {
    return q->rear == q->front;
}
int isFull(Queue* q) {
    return ( q->rear+1 ) % MAXSIZE == q->front;
}
void enQueue(Queue* q, int data) {
    if (isFull(q))
        return;
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % MAXSIZE;
}
int deQueue(Queue* q) {
    if (isEmpty(q))
        return -1;
    int res = q->data[q->front];
    q->front = ( q->front+1 ) % MAXSIZE;
    return res;
}
Graph* initGraph(int vexNum) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexNum = vexNum;
    G->arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i=0;i<vexNum;i++) {
        G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G->vexs =(char*)malloc(sizeof(int) * vexNum);
    G->arcNum = 0;
    return G;
}
void createGraph(Graph* G, char* vexs,int* arcs) {
    for (int i = 0;i < G->vexNum ; i++) {
        G->vexs[i] =  vexs[i];
        for (int j=0;j<G->vexNum;j++) {
            G->arcs[i][j] = *(arcs+i*G->vexNum+j);
            if (*(arcs+i*G->vexNum+j) != 0)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}
void DFS(Graph* G, int index, int* visited) {
    printf("%c ", G->vexs[index]);
    visited[index] = 1;
    for (int i=0;i<G->vexNum;i++) {
        if (!visited[i] && G->arcs[index][i] != 0) {
            DFS(G, i, visited);
        }
    }
}
int isIn(Queue* q, int index) {
    for (int i=q->front ; i != q->rear ; i = (i+1) % MAXSIZE)
        if (index == q->data[i])
            return 1;
    return 0;
}
void BFS(Graph* G, int index, int* visited) {
    Queue* q = initQueue();
    enQueue(q, index);
    while (!isEmpty(q)) {
        int i= deQueue(q);
        printf("%c ", G->vexs[i], visited[i]);
        visited[i] = 1;
        for (int j=0;j<G->vexNum;j++) {
            if (G->arcs[i][j] == 1 && !visited[j] && !isIn(q, j)) {
                enQueue(q, j);
            }
        }
    }
}
int main(){
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    Graph* G = initGraph(5);
    int *visited = (int*)malloc(sizeof(int) * G->vexNum);
    for (int i=0;i<G->vexNum;i++)
        visited[i] = 0;
    createGraph(G, "ABCDE", (int*)arcs);
    BFS(G, 0, visited);
}
