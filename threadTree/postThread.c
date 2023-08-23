#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
    int ltag;
    int rtag;
}TreeNode;

TreeNode* initTree(char* data, int* index, TreeNode* parent) {
    char ch = data[*index];
    *index += 1;
    if (ch != '#') {
        TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
        head->ltag = head->rtag = 0;
        head->data = ch;
        head->left = initTree(data, index, head);
        head->right = initTree(data, index, head);
        head->parent = parent;
        return head;
    }
    else
        return NULL;
}
/*
找第一个节点：
    1. 找到最左边的节点
    2. 判断这个最左边的节点是否有右子树，如果有就找这个右子树的最左边的，
    如果没有，那么第一个节点就是这个最左边的
*/
TreeNode* getFirst(TreeNode* T){
    while (T->ltag == 0)
        T = T->left;
    if (T->rtag == 0)
        return getFirst(T->right);
    else
        return T;   
}
TreeNode* getNext(TreeNode* T) {
    if (T->rtag == 1) // 没有右子树
        return T->right; 
    else {
        if (T->parent == NULL) // 是根节点
            return NULL;
        else if (T->parent->right == T) //如果是右孩子    
            return T->right;
        else {// 如果是左孩子
            if (T->parent->rtag == 0)   //有右孩子
                return getFirst(T->parent->right);
            else                            //没有右子树 
                return T->parent;
        }
    }    
}
void postThread(TreeNode* T, TreeNode** pre){
    if (T) {
        postThread(T->left, pre);
        postThread(T->right, pre);
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
    }
}
 
void print(TreeNode* T){
    for (TreeNode* node = getFirst(T) ; node != NULL ; node = getNext(node)) {
        printf("%c->", node->data);
    }
    printf("NULL");
}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* T = initTree(argv[1], &index, NULL);
    TreeNode*  pre = NULL;
    postThread(T, &pre);
    print(T);
    return 0;
}