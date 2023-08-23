#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
    int ltag;
    int rtag;
}TreeNode;

TreeNode* initTree(char* data, int* index) {

    char ch = data[*index];
    *index += 1;
    if (ch != '#') {
        TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
        head->ltag = head->rtag = 0;
        head->data = ch;
        head->left = initTree(data, index);
        head->right = initTree(data, index);
        return head;
    }
    else
        return NULL;
}

void postThread(TreeNode* T, TreeNode** pre){
    if (T) {
         // 办事
        if (T->left == NULL) {// 没有左孩子，就指向前驱    
            T ->left = *pre;
            T->ltag = 1;
        }
        if ((*pre) != NULL && (*pre)->right == NULL) {
            (*pre)->right = T;
            (*pre)->rtag = 1;
        }
        (*pre) = T;
        if (T->ltag == 0)
            postThread(T->left, pre);
        postThread(T->right, pre);
    }
}
TreeNode* getNext(TreeNode* T) {
    if (T->rtag == 1) // 此时没有有孩子
        return T->right;
    else { // 有右孩子
        if (T->ltag == 0) // 有左孩子
            return T->left;
        else              // 没左孩子 
            return T->right;
    } 

}
void print(TreeNode* T){
    for (TreeNode* node = T ; node != NULL ; node = getNext(node)) {
        printf("%c->", node->data);
    }
    printf("NULL");
}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* T = initTree(argv[1], &index);
    TreeNode*  pre = NULL;
    postThread(T, &pre);
    pre->rtag = 1;
    pre->right = NULL;
    print(T);
    return 0;
}