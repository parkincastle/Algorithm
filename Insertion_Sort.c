#include <stdio.h>
#define SIZE 8

int main() {

	int temp, key, j;
	int num[] = { 3, 8, 2, 1, 7, 4, 6, 5 };

	printf("정렬 전 : ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		key = num[i];
		
		for (j = i - 1; j >= 0 && num[j] > key; j--) {
			num[j + 1] = num[j];
		}
		num[j + 1] = key;
		printf("i : %d, j : %d \n",i, j);

	}

	printf("정렬 후 : ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", num[i]);

	}



	return 0;
}