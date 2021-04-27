#include <stdio.h>
#define SIZE 8
int tmp[SIZE];

void marge(int data[], int left, int mid, int right) {
	int L, R, k, a;
	L = left;
	R = mid + 1;
	k = left;

	while (L <= mid && R <= right)
		tmp[k++] = data[L] <= data[R] ? data[L++] : data[R++];

	if (L > mid)
		for (a = R; a <= right; a++)
			tmp[k++] = data[a];
	else
		for (a = L; a <= mid; a++)
			tmp[k++] = data[a];

	for (a = left; a <= right; a++)
		data[a] = tmp[a];

}

void margeSort(int data[], int left, int right) {
	int mid;

	if (left == right)
		return;

	mid = (left + right) / 2;

	if (left < right) {
		margeSort(data, left, mid);
		margeSort(data, mid + 1, right);
		marge(data, left, mid, right);
	}
	
}

void Print(int data[]) {
	int i;

	for (i = 0; i < SIZE; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main() {
	int data[] = { 3, 6, 1, 7, 11, 2, 5, 4 };
	int i;

	printf("정렬 전 : ");
	Print(data);

	margeSort(data, 0, SIZE-1);

	printf("정렬 후 : ");
	Print(data);
}