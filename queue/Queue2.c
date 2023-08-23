#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int data;
    struct Queue* next;
}QueueNode;
//第一个节点是头节点，存储队列的大小
QueueNode* initQueue(){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    return node;
}
int Size(QueueNode* q){
    return q->data;
}
void enQueue(QueueNode* q, int data){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    QueueNode* Q = q;
    node->data = data;
    int size = q->data;
    for (int i=0; i<size ;i++,Q = Q->next);
    node->next = Q->next;
    q->data ++;
    Q->next = node;
}
int deQueue(QueueNode* q){
    QueueNode* node = q->next;
    q->next = node->next;
    q->data --;
    return node->data;
}
int isEmpty(QueueNode* q){
    return q->data == 0;
}
void Travel(QueueNode* q){
    QueueNode* p = q->next;
    while (p){
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
int main(){
    QueueNode* q = initQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    Travel(q);
    deQueue(q);
    Travel(q);
}