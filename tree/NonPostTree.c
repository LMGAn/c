#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
    int flag;
}TreeNode;

typedef struct Stack
{
    TreeNode* data;
    struct Stack* next;   
}Stack;
TreeNode* initTree(char* data, int* index){
    char ch = data[*index];
    *index += 1;
    if (ch == '#')
        return NULL;
    else{
        TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
        T->data = ch;
        T->left = initTree(data, index);
        T->right = initTree(data, index);
        T->flag = 0;
        return T;
    }
}
Stack* initStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->data = NULL;
    stk->next = NULL;
    return stk;
}
void push(Stack* stk, TreeNode* T){
    Stack* node = (Stack*)malloc(sizeof(Stack)) ;
    node->data = T;
    node->next = stk->next;
    stk->next = node;
}
int isEmpty(Stack* stk) {
    return stk->next == NULL;
}
TreeNode* getTop(Stack* stk) {
    if (isEmpty(stk))
        return NULL;
    else
        return stk->next->data;
}
void pop(Stack* stk){
    Stack* s = stk->next;
    stk->next = s->next;
    free(s);
}
/**
 * 1. 从根节点出发寻找最左边的节点，并依次入栈
 * 2. 如果T指向null， 判断栈顶元素有没有右子树，且右子树有没有被访问过，如果有右子树而且没有被访问过，就入栈
 * 3. 如果没有右子树或者有右子树但是被访问过，就直接出栈并访问
*/
void postTravel(TreeNode* node){
    Stack* stk = initStack();
    TreeNode* T = node;
    while (T || !isEmpty(stk)) {
        if (T) {
            push(stk, T);
            T = T->left;
        }
        else {
            TreeNode* top = getTop(stk);
            if (top->right && top->right->flag == 0)
                push(stk, top->right);
            else{
                pop(stk);
                printf("%c ",top->data);
                top->flag = 1;
            }
        }
    }

}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* T = initTree(argv[1], &index);
    postTravel(T);
    return 0;
}
