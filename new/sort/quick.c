#include<stdio.h>
#include<stdio.h>
void quick(int arr[], int L, int R){
    if (L >= R) 
        return;
    int left = L, right = R;
    int pivot = arr[L];
    while (left < right){
        while (left < right && pivot <= arr[right])
            right--;
        if(left < right)
            arr[left] = arr[right];
        while (left < right && pivot >= arr[left])
            left++;
        if(left < right)
            arr[right] = arr[left];
        if (left >= right)
            arr[left] = pivot;
    }
    quick(arr, L, right-1);
    quick(arr, right+1, R);
    
}
void sort(int arr[], int size){
    quick(arr, 0, size);
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