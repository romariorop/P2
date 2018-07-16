#include <stdio.h>
void quickSort(int numbers[], int left, int right) {
    int mid = (left + right) / 2;
    int pivot = numbers[mid];
    int l = left;
    int r = right;
    while(l <= r){
        while(l <= right && numbers[l] < pivot)++l;
        while(r >= left && numbers[r] > pivot)--r;
        if(l <= r){
            int temp = numbers[l];
            numbers[l] = numbers[r];
            numbers[r] = temp;
            l++, r--;
        }
    }
    if(r > left) quickSort(numbers, left, r);
    if(l < right) quickSort(numbers, l, right);
}

int main() {
    int aux[100];
    int numbers[] = {6, 6, 2, 7, 2, 5, 7};
    for(int i = 0; i < 7; ++i) printf(" %d", numbers[i]);
    puts("");
    quickSort(numbers, 0, 6);
    for(int i = 0; i < 7; ++i) printf(" %d", numbers[i]);
    puts("");
    return 0;
}