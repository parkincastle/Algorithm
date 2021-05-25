// heap(Tree) 완전이진 트리
// 삽입 : 맨 마지막
// 삭제 : root
// 최대 : 부모 >= 자식
// 최소 : 부코 <= 자식

#include <stdio.h>

int num_of_data = 9;
int data[] = { 9, 2, 1, 6, 5, 3, 7, 8, 4 };

int main() {

	for (int i = 1; i < num_of_data; i++) {
		
		int c = i;

		do {
			int root = (c - 1) / 2;

			if (data[root] < data[c]) {
				int temp = data[root];
				data[root] = data[c];
				data[c] = temp;
			}

			c = root;

		} while (c != 0);

	}

	for (int i = num_of_data - 1; i >= 0; i--) {

		int root = 0;
		int c = 1;
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		
		do {
			c = 2 * root + 1;

			if (c < i - 1 && data[c] < data[c + 1]) {
				c++;
			}

			if (c < i && data[root] < data[c]) {
				temp = data[root];
				data[root] = data[c];
				data[c] = temp;
			}
			root = c;
		} while (c < i);
		
		for (int i = 0; i < num_of_data; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");

	}
}