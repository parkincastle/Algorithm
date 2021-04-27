#include <stdio.h>
#define SIZE 6

int main() {

	int i, j, k, temp = 0;
	int a[] = { 5, 4, 6, 1, 3, 2 };

	printf("초기값 : ");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");



	for (i = 0; i < SIZE-1; i++) {

		for (j = 0; j < SIZE -1-i; j++) {

			if (a[j] > a[j+1]) {

				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

		}
		printf("%d번값 : ", i);
		for (k = 0; k < SIZE; k++) {
			printf("%d ", a[k]);
		}
		printf("\n");

	}

	for (i = 0; i < SIZE; i++) {
		printf("최종값 : %d ", a[i]);
	}
}