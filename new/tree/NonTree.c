#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
typedef struct Stack{
    TreeNode* val;
    struct Stack* next;
}Stack;
TreeNode* createTree(char *data, int* index){
    char ch = data[*index];
    *index += 1;
    if (ch != '#') {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = ch;
        node->left = createTree(data, index);
        node->right = createTree(data, index);
        return node;
    }
    else
        return NULL;
}
int isEmpty(Stack* stk){
    return stk->next == NULL;
}
Stack* initStack(){
    Stack* stk = (Stack*)malloc(sizeof(stk));
    stk->next = NULL;
    return stk;
}
void push(Stack* stk, TreeNode* tree) {
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->val = tree;
    node->next = stk->next;
    stk->next = node;
}
TreeNode* pop(Stack* stk){
    Stack* node = stk->next;
    stk->next = node->next;
    return node->val;
}
void preTravel(TreeNode* head) {
    Stack* stk = initStack();
    TreeNode* T = head;
    while (T || !isEmpty(stk)) {
        if (T) {
            printf("%c ", T->val);
            push(stk, T);
            T = T->left;
        }
        else {
            T = pop(stk);
            T = T->right;
        }
    }
}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* head = createTree(argv[1], &index);
    preTravel(head);
    return 0;
}
