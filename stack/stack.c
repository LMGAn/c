#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    char data;
    struct Stack* next;
}Stack;
Stack* initStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->next = NULL;
    return stk;
}
void push(Stack* stk, char data){
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->data = data;
    node->next = stk->next;
    stk->next = node;
}
char pop(Stack* stk) {
    char ch = stk->next->data;
    stk->next = stk->next->next;
    return ch;
}
void print(Stack* stk){
    Stack* node = stk->next;
    while (node) {
        printf("%c ->", node->data);
        node = node->next;
    }
}
int main(){
    Stack* stk = initStack();
    push(stk, 'a');
    push(stk, 'a');
    push(stk, 'a');
    push(stk, 'a');
    push(stk, 'a');
    print(stk);
}