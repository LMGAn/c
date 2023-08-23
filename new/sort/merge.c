#include<stdio.h>
#include<stdlib.h>
void sort(int arr[], int temp[], int L, int mid, int R){   
    if (L >= R)
        return;
    int lpos = L, rpos = mid+1;
    int pos = L;
    while (lpos <= mid && rpos <= R) {
        if (arr[lpos] < arr[rpos])
            temp[pos++] = arr[lpos++];
        else
            temp[pos++] = arr[rpos++];
    }
    while(lpos <= mid)
        temp[pos++] = arr[lpos++];
    while (rpos <= R)
        temp[pos++] = arr[rpos++];
    while (L <= R) {
        arr[L] = temp[L];
        L++;
    }
}
void merge(int arr[], int temp[], int L, int R){
    if (L < R) {
        int mid = (L + R) / 2;
        merge(arr, temp, L, mid);
        merge(arr, temp, mid+1, R);
        sort(arr, temp, L, mid, R);       
    }
}
void merge_sort(int arr[], int size){
    int *temp = (int *)malloc(sizeof(int) * size);
    merge(arr, temp, 0, size-1);    
    free(temp);
}
void print(int arr[], int size) {
    for (int i=0;i<size;i++) 
        printf("%d ", arr[i]);
}
int main(){
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    merge_sort(arr, 10);
    print(arr, 10);   
}
