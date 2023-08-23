#include<stdio.h>
#include<stdlib.h>
#define MAX 32767
typedef struct Graph{
    char *vexs;
    int vexNum;
    int arcNum;
    int **arcs;
}Graph;
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
            if (*(arcs+i*G->vexNum+j) != 0 && G->arcs[i][j] != MAX)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}
int getMin(Graph* G, int* s, int* d){
    int index;
    int min = MAX;
    for (int i=0;i<G->vexNum;i++) {
        if (!s[i] && min > d[i]){ 
            min = d[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(Graph* G, int index) {
    int* s = (int*)malloc(sizeof(int) * G->vexNum);  // 最短路径是否确定
    int* p = (int*)malloc(sizeof(int) * G->vexNum); // 记录所有节点的前驱
    int* d = (int*)malloc(sizeof(int) * G->vexNum); // 记录目标顶点到该节点的最短路径的长度
    for (int i=0;i<G->vexNum;i++) {
        if (i == index) 
            s[i] = 1;
        else
            s[i] = 0;

        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX)
            p[i] = index;
        else
            p[i] = -1;
        if (i == index) d[i] = 0;
        else d[i] = G->arcs[index][i];
    }
    for (int i=0;i<G->vexNum;i++) {
        printf("%d %d %d\n", s[i], p[i],d[i]);
    }
    for (int i=0;i<G->vexNum-1;i++) {
        int index = getMin(G, s,p);
        s[index] = 1;
        for (int j=0;j<G->vexNum;j++) {
            if (!s[j] && d[index] + G->arcs[index][j] < d[j]) { 
                d[j] = d[index] + G->arcs[index][j];
                p[j] = index;
            }
        }
    }    
}
void DFS(Graph* G, int index, int* visited) {
    printf("%c ", G->vexs[index]);
    visited[index] = 1;
    for (int i=0;i<G->vexNum;i++) {
        if (!visited[i] && G->arcs[index][i] > 0 && G->arcs[index][i] != MAX) {
            DFS(G, i, visited);
        }
    }
}
int main(){
    int arcs[7][7] = {
        0, 12, MAX, MAX, MAX, 16, 14,
        12, 0, 10, MAX, MAX, 7, MAX,
        MAX, 10, 0, 3, 5, 6, MAX,
        MAX, MAX, 3, 0,4 ,MAX, MAX,
        MAX, MAX, 5, 4, 0, 2, 8,
        16, 7, 6, MAX, 2, 0, 9,
        14, MAX, MAX, MAX, 8, 9, 0
    };
    Graph* G = initGraph(7);
    int *visited = (int*)malloc(sizeof(int) * G->vexNum);
    for (int i=0;i<G->vexNum;i++)
        visited[i] = 0;
    createGraph(G, "1234567", (int*)arcs);
    dijkstra(G, 0);
}
