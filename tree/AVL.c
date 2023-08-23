#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
int getHeight(TreeNode* T){
    return T ? T->height : 0;
}
int max(int a, int b){
    return a > b? a : b;
}
int Height(TreeNode* T) {
    return max(getHeight(T->left), getHeight(T->right)) + 1;
}
void llRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->height = Height(temp);
    node->height = Height(node);
    *root = node;
}
void rrRotation(TreeNode* node, TreeNode** root) { // node是爷爷节点 temp是中间节点
    TreeNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = Height(node);
    temp->height = Height(temp);
    *root = node;
}
void avlInsert(TreeNode** T, int key){
    if ((*T) == NULL) {
        (*T) = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = key;
        (*T)->height = 0;
        (*T)->left = NULL;
        (*T)->right = NULL;
    }
    else if (key < (*T)->data) {
        avlInsert(&((*T)->left), key);
        // 拿到当前左右节点的高度
        int lheight = getHeight((*T)->left);
        int rheight = getHeight((*T)->right);
        // 判断高度差
        if (lheight - rheight == 2) {
            if (key < (*T)->left->data) //LL调整
                llRotation(*T, T);
            else { // LR调整
                rrRotation((*T)->left, &((*T)->left));
                llRotation(*T, T);
            }
        }
    }
    else if (key >(*T)->data){
        avlInsert(&((*T)->right), key);
        int lheight = getHeight((*T)->left);
        int rheight = getHeight((*T)->right);
        // 判断高度差
        if (rheight - lheight == 2) {
            if (key > (*T)->right->data) //RR调整
                rrRotation(*T,T);
            else { // RL调整
                llRotation((*T)->right, &((*T)->right));
                rrRotation(*T,T);
            }
        }
    }
    (*T)->height = Height(*T);
}
void preOrder(TreeNode* T){
    if (T){
        printf("%d ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}
int main(){
    int nums[] = {1,2,3,4,5};
    TreeNode* T = NULL;
    for (int i=0;i<5;i++){
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    putchar('\n');
}