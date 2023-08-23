#include<stdio.h>
#include<stdlib.h>
void shell(int arr[], int size){
    int inc = size / 2, i, j;
    for ( ; inc > 0 ; inc /= 2) {
        for ( i = inc ; i< size ; i++) {
            int pos = arr[i];
            for ( j=i;j >= inc && pos < arr[j-inc];j -= inc) {
                arr[j] = arr[j-inc];
            }
            arr[j] = pos;
        }
    } 
}
void print(int arr[], int n) {
    for (int i=0;i<n;i++) 
        printf("%d ", arr[i]);
}
int main() {
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    shell(arr, 10);
    print(arr, 10);   
}
