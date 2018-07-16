#include <stdio.h>
void merge(int numbers[], int half1Begin, int half1End, int half2Begin, int half2End, int aux[]){
    int index = 0, left = half1Begin, right = half2End;
    while(half1Begin <= half1End || half2Begin <= half2End) {
        if(half1Begin > half1End){ //// lista 1 acabou
            while(half2Begin <= half2End){
                aux[index++] = numbers[half2Begin++];
            }
        }else if(half2Begin > half2End) { //lista 2 acabou
            while(half1Begin <= half1End){
                aux[index++] = numbers[half1Begin++];
            }
        }else {  // nenhuma das duas listas acabou
            if(numbers[half1Begin] < numbers[half2Begin]){
                aux[index++] = numbers[half1Begin++];
            }else {
                aux[index++] = numbers[half2Begin++];
            }
        }
    }
    index = 0;
    for(int i = left; i <= right; ++i, ++index) {
        numbers[i] = aux[index];
    }
}

void mergeSort(int numbers[], int left, int right, int aux[]) {
    if(left == right) return;
    int mid = (left + right)/2;
    mergeSort(numbers, left, mid, aux);
    mergeSort(numbers, mid+1, right, aux);
    merge(numbers, left, mid, mid+1, right, aux);
}

int main() {
    int aux[100];
    int numbers[] = {6, 4, 2, 1, 3, 5, 7};
    for(int i = 0; i < 7; ++i) printf(" %d", numbers[i]);
    puts("");
    mergeSort(numbers, 0, 6, aux);
    for(int i = 0; i < 7; ++i) printf(" %d", numbers[i]);
    puts("");
    return 0;
}