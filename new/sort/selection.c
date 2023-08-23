#include<stdio.h>
#include<stdio.h>
void selection(int arr[], int size){
    int i,j,k;
    for (i=1;i<size;i++) {
        j = i-1;
        int pos = arr[i];
        while (j >= 0 && pos < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pos;   
    }
}
void sort(int arr[], int size){
    selection(arr, size);
}
void print(int arr[], int size) {
    for (int i=0;i<size;i++) 
        printf("%d ", arr[i]);
}
int main(){
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    sort(arr, 10);
    print(arr, 10);
}