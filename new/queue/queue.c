#include<stdio.h>
#include<stdlib.h>
typedef struct QueueNode{
    int val;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
}Queue;
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int isEmpty(Queue* q) {return q->front == NULL;}
void enQueue(Queue* q, int val) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->val = val;
    node->next = NULL;
    if (isEmpty(q)){
        q->front = node;
        q->rear = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
        
    }
}
int deQueue(Queue* q) {
    if (isEmpty(q)){
        return -1;
    }
    QueueNode* node = q->front;
    int data = node->val;
    free(node);
    return data;
}
void Travel(Queue* q) {
    for(QueueNode* node = q->front;node != NULL ;node = node->next )
        printf("%d ", node->val);
}
int main(){
    Queue* q = initQueue();
    enQueue(q, 10);
    enQueue(q, 10);
    enQueue(q, 10);
    enQueue(q, 10);
    Travel(q);
}