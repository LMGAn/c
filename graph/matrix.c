#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct Graph {
    char* vexs;
    int** arcs;
    int vexNum; 
    int arcNum;
}Graph;
typedef struct Queue {   
    int front;
    int rear;
    int* data;
}Queue;
int getSize(Queue* q) {
    return ( q->front - q->rear + MAXSIZE ) % MAXSIZE;
}
Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
   return q;
}
int isFull(Queue* q) {
    return q->front == (q->rear + 1) % MAXSIZE;
}
int isEmpty(Queue* q){
    return q->front == q->rear;
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
Graph* initGraph(int vexNum){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char) * vexNum);
    G->arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i=0;i<vexNum;i++)
        G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}
void createGraph(Graph* G, char* vexs, int* arcs) {
    for (int i=0;i<G->vexNum;i++){
        G->vexs[i] = vexs[i];
        for (int j=0;j<G->vexNum;j++) {
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if (G->arcs[i][j] != 0)
            G->arcNum ++;
        }
    }
    G->arcNum /= 2;
}
// 遍历算法 , 深度优先
void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    for (int i=0;i<G->vexNum;i++){
        if (G->arcs[index][i] == 1 && !visited[i]) {
            DFS(G, visited, i);
        }
    }
}
void BFS(Graph* G, int* visited, int index) {
    Queue* q = initQueue();
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    enQueue(q, index);
    while (!isEmpty(q)) {
        int i = deQueue(q);
        for (int j=0;j<G->vexNum;j++){
            if (G->arcs[i][j] == 1 && !visited[j]) {
                printf("%c\t", G->vexs[j]);
                visited[j] = 1;
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
    DFS(G, visited, 0);
    putchar('\n');
    for (int i=0;i<G->vexNum;i++)
        visited[i] = 0;
    BFS(G, visited, 0);
    putchar('\n');
    return 0;
}
