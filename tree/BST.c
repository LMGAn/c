#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* right;
    struct TreeNode* left;
}TreeNode;
TreeNode* bstSearch(TreeNode* T, int key) {
    if (T){
        if (T->data == key)
            return T;
        else if (T->data > key)
            return bstSearch(T->left, key);
        else    
            return bstSearch(T->right, key);
    }
    else    
        return NULL;
}
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
        return T;
    }
}
void bstInsert(TreeNode** bst, int key){
    if ((*bst) == NULL) {
        (*bst) = (TreeNode*)malloc(sizeof(TreeNode));
        (*bst)->data = key;
        (*bst)->left = (*bst)->right = NULL;
    }
    else if ((*bst)->data == key){
        printf("repeatedly");
        return;
    }
    else if ((*bst)->data > key)
        bstInsert(&((*bst)->left), key);
    else
        bstInsert(&((*bst)->right), key);
}
void preOrder(TreeNode* T){
    if (T){
        preOrder(T->left);
        printf("%d ", T->data);
        preOrder(T->right);
    }
}
int main(int argc, char *argv[])
{
    TreeNode* T = NULL;
    int nums[] = {4, 5, 19, 23, 2, 8};
    for (int i=0;i<6;i++){
        bstInsert(&T, nums[i]);
    }
    preOrder(T);
    putchar('\n');
    return 0;
}
