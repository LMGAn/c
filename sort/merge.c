#include<stdio.h>
#include<stdlib.h>
void sort(int arr[], int tempArr[], int L, int mid, int R) {
    int lpos = L, rpos = mid+1, pos = L;
    while (lpos <= mid && rpos <= R) {
        if (arr[lpos] < arr[rpos])
            tempArr[pos++] = arr[lpos++];
        else
            tempArr[pos++] = arr[rpos++];
    }
    while (lpos <= mid) 
        tempArr[pos++] = arr[lpos++]; 
    while (rpos <= R) 
        tempArr[pos++] = arr[rpos++];
    while (L <= R) {
        arr[L] = tempArr[L];
        L ++;
    }
}
void merge(int arr[],int tempArr[], int L, int R) {
    if (L<R) {
        int mid = (R+L)/2;
        merge(arr, tempArr, L, mid);
        merge(arr, tempArr, mid+1, R);
        sort(arr, tempArr, L, mid, R);       
    }
}
void merge_sort(int arr[], int n){
    int * tempArr = (int*)malloc(sizeof (int) * n);
    if (tempArr) {
        merge(arr, tempArr, 0, n-1);
        free(tempArr);
    }
    else
        printf("error:failed to allocate");
}
void print(int arr[], int n) {
    for (int i=0;i<n;i++) 
        printf("%d ", arr[i]);
}
int main(){
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    merge_sort(arr, 10);
    print(arr, 10);
}