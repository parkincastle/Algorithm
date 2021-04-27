#include <stdio.h>

void QuickSort(int arr[], int left, int right) {

    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ

    while (L <= R) {    // �Ÿ���
        while (arr[L] < pivot) // left���� �����ϸ� pivot �̻��� ���� ã��
            L++;
        while (arr[R] > pivot) // right���� �����ϸ� pivot ���� ���� ã��
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

    printf("���� �� ���� : "); // �����ϱ� �� ���� ���
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    QuickSort(data, 0, 9);

    printf("���� �� ���� : "); // ������ �� ���� ���
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}