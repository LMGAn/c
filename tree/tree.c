#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
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
void preTravel(TreeNode* head) {
    if (head) {
        printf("%c ", head->data);
        preTravel(head->left);
        preTravel(head->right);
    }
}
void inTravel(TreeNode* head) {
    if (head) {
        inTravel(head->left);
        printf("%c ", head->data);
        inTravel(head->right);
    }
}
void postTravel(TreeNode* head) {
    if (head) {
        inTravel(head->left);
        inTravel(head->right);
        printf("%c ", head->data);
    }
}
int main(int argc, char *argv[])
{
    int index = 0;
    TreeNode* head = initTree(argv[1], &index);
    inTravel(head);
    return 0;
}
