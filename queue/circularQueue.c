#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct Queue{
    int front;
    int rear;
    int *data;
}Queue;
Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int)*MAXSIZE);
    q->front = q->rear = 0;
    return q;
}

int isEmpty(Queue* q){
    return q->rear == q->front;
}
int isFull(Queue* q){
    return (q->rear+1) % MAXSIZE == q->front;
}
void enQueue(Queue* q, int data){
    if (isFull(q)){
        printf("full");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear+1) % MAXSIZE;
}
int getSize(Queue* q) {
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}
int deQueue(Queue* q){
    if (isEmpty(q)){
        printf("empty");
        return -1;
    }
    int data = q->data[q->front];
    q->front = ( q->front+1 ) % MAXSIZE; 
    return data;
}
void print(Queue* q){
    for (int i=q->front+1; i!=1+q->rear;i = (i+1) % MAXSIZE)
        printf("%d ", q->data[i]);
}
int main(){
    Queue* q = initQueue();
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    deQueue(q);
    print(q);

}