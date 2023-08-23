#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* next;   
}Node;
typedef struct QueueNode{
    Node* first;
    Node* end;
}QueueNode;
QueueNode* initQueue(){
    QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
    q->end = NULL;
    q->first = NULL;
    return q;
}
int isEmpty(QueueNode* q){
    return q->first == NULL;
}
void enQueue(QueueNode* q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = data;
    if (isEmpty(q)){
        q->first = node;
        node->next = NULL;
        q->end = node;
    }
    else{
        q->end->next = node;
        q->end = node;
    }
}
int deQueue(QueueNode* q){
    if (isEmpty(q))
        return -1;
    Node* node = q->first;
    q->first = node->next;
    return node->val;      
}
int main() {
          
}