#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i) {
    int lson = i*2+1;
    int rson = i*2+2;
    int biggest = i;
    if (lson < size && arr[biggest] < arr[lson])
        biggest = lson;
    if (rson < size && arr[biggest] < arr[rson])
        biggest = rson;
    if (biggest != i) {
        swap(&arr[i], &arr[biggest]);
        heapify(arr, size, biggest);
    }
}
void sort(int arr[], int size) {
    // 建立堆
    for (int i = i/2-1 ; i >= 0 ; i-- ){
        heapify(arr, size, i);
    }
    // 排序
    for (int i=size-1;i>=0;i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int n) {
    for (int i=0;i<n;i++) 
        printf("%d ", arr[i]);
}
int main() {
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    sort(arr, 10);
    print(arr, 10);   
}