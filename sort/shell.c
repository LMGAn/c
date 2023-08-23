#include<stdio.h>
void shell(int arr[], int n) {
    int key,j,inc,i;
    for (inc = n / 2;inc > 0 ; inc /= 2) {
        for ( i=inc ; i < n ; i ++) {
            key = arr[i];
            for (j = i; j >= inc && arr[j-inc] > key ; j-=inc)
                arr[j] = arr[j-inc];
            arr[j] = key;
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