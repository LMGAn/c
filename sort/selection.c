#include<stdio.h>
void selection(int arr[], int n) {
    for (int i=1;i<n;i++) {
        int j = i-1;
        int pos = arr[i];
        while (arr[j] > pos && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pos;
    }
}
void print(int arr[], int n) {
    for (int i=0;i<n;i++) 
        printf("%d ", arr[i]);
}
int main() {
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    selection(arr, 10);
    print(arr, 10);   
}