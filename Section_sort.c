#include <stdio.h>
#define SIZE 8

int main() {
	int num[] = { 3, 8, 2, 1, 7, 4, 6, 5 };
	int temp;

	printf("정렬 전 : ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (num[i] > num[j]) {
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}

	printf("정렬 후 : ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", num[i]);

	}

}