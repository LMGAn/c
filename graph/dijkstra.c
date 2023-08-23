#include<stdio.h>
#include<stdlib.h>
#define MAX 32767
typedef struct Graph {
    char* vexs;
    int** arcs;
    int vexNum; // 顶点数
    int arcNum; // 边数
}Graph;
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
            if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX) //带权值的图
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
        if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]) {
            DFS(G, visited, i);
        }
    }
}
int getMin(Graph* G, int *s, int *d) {
    int min = MAX;
    int index;
    for (int i=0;i<G->vexNum;i++) {
        if (!s[i] && d[i] < min) { // 最短距离还没确定 而且的d[i]小于最小值min
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
     //  初始化
    for (int i=0;i<G->vexNum;i++) {
        if (index == i) 
            s[i] = 0;
        else
            s[i] = 0;
        
        if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX)
            p[i] = index;
        else
            p[i] = -1;
        if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX) //有权图
            d[i] = G->arcs[index][i];
        else
            d[i] = MAX;           
        if (index == i)
            d[i] = 0;
    }
    for (int i=0;i<G->vexNum-1;i++) {
        int index = getMin(G, s, d);
        s[index] = 1;
        for (int j=0;j<G->vexNum;j++) {
            if (!s[j] && G->arcs[index][j] + d[index] < d[j]) {
                d[j] = G->arcs[index][j] + d[index];
                p[j] = index;
            }
        } 
    }       
    for (int i=0;i<G->vexNum;i++) {
        printf("%d %d %d\n", s[i], p[i],d[i]);
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
    return 0;
}
