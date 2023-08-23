//带权路径长度最小的树
/*
1. 要使用指定权值的节点生成哈夫曼树
2. 遍历哈夫曼树
3. 取节点序列最小的两个节点
4. 想一想树的存储结构
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int weight;
    int parent;
    int left;
    int right;
}TreeNode;
typedef struct HFTree{
    TreeNode* data;
    int length;
}HFTree;
HFTree* iniTree(int* weight, int length){
    HFTree* T = (HFTree*)malloc(sizeof(HFTree));
    T->data = (TreeNode*)malloc(sizeof(TreeNode) * ( 2*length-1) );
    T->length = length;
    for (int i=0;i<length;i++) {
        T->data[i].weight = weight[i];
        T->data[i].parent = 0;
        T->data[i].left = -1;
        T->data[i].right = -1;
    }
    return T;
}
int* selectMin(HFTree* T){
    int min = 10000,secMin = 10000, minIdx,secIdx;
    for (int i=0;i<T->length;i++){
        if (T->data[i].parent == 0){ // 这个是没有父亲的
            if (T->data[i].weight < min) {
                min = T->data[i].weight;
                minIdx  = i; 
            }
        }
    }
    for (int i=0;i<T->length;i++){
        if (T->data[i].parent == 0 && i != minIdx){
            if (T->data[i].weight < secMin) {
                secMin = T->data[i].weight;
                secIdx  = i; 
            }
        }
    }
    int * res = (int*)malloc(sizeof(int)*2);
    res[0] = minIdx;
    res[1] = secIdx;
    return res;
}
void createHFM(HFTree* T){
    int* res,min,secMin;
    int length = T->length * 2 - 1;
    for (int i = T->length ; i < length;i++) {
        res = selectMin(T);
        min = res[0];
        secMin = res[1];
        T->data[i].weight = T->data[min].weight + T->data[secMin].weight;
        T->data[i].left = min;
        T->data[i].right = secMin;
        T->data[min].parent = i;
        T->data[secMin].parent = i;
        T->length ++;
    }   
} 
void preOrder(HFTree* T, int index){
    if (index != -1){
        printf("%d ", T->data[index].weight);
        preOrder(T, T->data[index].left);
        preOrder(T, T->data[index].right);
    }
}
int main(){
    int weight[4] = {1, 2,3 ,4};
    HFTree* T = iniTree(weight, 4);
    createHFM(T);
    preOrder(T, T->length - 1);
    return 0;   
}