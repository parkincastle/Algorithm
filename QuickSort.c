#include <stdio.h>

void QuickSort(int arr[], int left, int right) {

    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2]; //피봇 위치

    while (L <= R) {    // 거름망
        while (arr[L] < pivot) // left부터 증가하며 pivot 이상의 값을 찾음
            L++;
        while (arr[R] > pivot) // right부터 감소하며 pivot 이하 값을 찾음
            R--;

        if (L <= R) {
            if (L != R) {
                temp = arr[L];
                arr[L] = arr[R];
                arr[R] = temp;
            }
            L++;
            R--;
        }
    }
    if (left < R)
        QuickSort(arr, left, R);
    if (L < right)
        QuickSort(arr, L, right);
}

int main(void) {

    int data[10] = { 5, 9, 2, 4, 6, 1, 8, 3, 7, 10 };

    printf("정렬 전 순서 : "); // 정렬하기 전 상태 출력
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    QuickSort(data, 0, 9);

    printf("정렬 후 순서 : "); // 정렬한 후 상태 출력
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}