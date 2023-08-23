#include<stdio.h>
void sort(int arr[], int L, int R) {
   if (L >= R)
        return;
    int left = L, right = R, pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot)
            right --;
        if (left < right)
            arr[left] = arr[right];
         while (left < right && arr[left] <= pivot)
            left ++;
        if (left < right)
            arr[right] = arr[left];
        if (left >= right)  
            arr[left] = pivot;
    } 
    sort(arr,  L, right-1);
    sort(arr, right+1, R);
}
void print(int arr[], int n) {
    for (int i=0;i<n;i++) 
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = {4, 9, 2, 7, 8, 10, 1, 5, 6, 3};
    sort(arr, 0, 9);
    print(arr, 10);   
}