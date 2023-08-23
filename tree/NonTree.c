#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct Stack{
    struct Stack* next;
    TreeNode* data;     
}Stack;

TreeNode* initTree(char* data, int* index) {
    char ch = data[*index];
    *index += 1;
    if (ch != '#') {
        TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
        head->data = ch;
        head->left = initTree(data, index);
        head->right = initTree(data, index);
        return head;
    }
    else
        return NULL;
}
Stack* initStack() {
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->data = NULL;
    stk->next = NULL;
    return stk;
}

void push(Stack* stk, TreeNode* head) {
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->data = head;
    node->next = stk->next;
    stk->next = node;
}
TreeNode* pop(Stack* stk) {
    Stack* node = stk->next;
    stk->next = node->next;
    return node->data;
}

int isEmpty(Stack* stk) {
    return stk->next == NULL;
}

void preTravel(TreeNode* head) {
    Stack* stk = initStack();
    TreeNode* T = head;
    while ( T || !isEmpty(stk) ) {
        if (T) {
            push(stk, T);
            printf("%c ",T->data);
            T = T->left; 
        }
        else {
            T = pop(stk);
            T = T->right;
        }
    }
}

void inTravel(TreeNode* head) {
    Stack* stk = initStack();
    TreeNode* T = head;
    while ( T ||!isEmpty(stk) ) {
        if (T) {
            push(stk, T);
            T = T->left; 
        }
        else {
            T = pop(stk);
            printf("%c ", T->data);
            T = T->right;
        }
    } 
}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* head = initTree(argv[1], &index);
    inTravel(head);
    return 0;
}