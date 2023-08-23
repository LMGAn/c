#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    int lson = i*2+1;
    int rson = i*2+2;
    int largest = i;
    if (lson < n && arr[largest] < arr[lson])
        largest = lson;
    if (rson < n && arr[largest] < arr[rson])
        largest = rson;
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}
void sort(int arr[], int n) {
    // make heap
    for (int i=i/2-1;i>=0;i--)
        heapify(arr, n, i);
    // sort
    for (int i = n-1; i>=0 ;i--){
        swap(&arr[0], &arr[i]); 
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