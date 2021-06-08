#include <stdio.h>
#include <stdlib.h>

typedef struct _node {    // 연결 리스트의 노드 구조체
	struct _node* right;    // 오른쪽 노드의 주소를 저장할 포인터
	struct _node* left;		// 왼쪽 노드의 주소를 저장할 포인터
	int data;             // 데이터를 저장할 멤버
} Node;

Node* Serching_Node(Node* tree, int target) {
	if (tree == NULL) {
		printf("트리가 없습니다.");
		return 0;
	}
	if (tree->data == target) {
		printf("탐색 성공");
	}
	else if (tree->data < target) {	// 새로운 데이터가 더 클 때
		return Serching_Node(tree->right, target);
	}
	else {							// 새로운 데이터가 더 작을 때
		return Serching_Node(tree->left, target);
	}
}

void Insert_Node(Node** tree, Node* child) {

	if ((*tree)->data < child->data) {			// root의 값 보다 자식의 값이 큰 경우
		if ((*tree)->right == NULL) {	// root의 오른쪽 자식이 없을 경우
			(*tree)->right = child;
		}
		else{							// root의 자식이 있을경우 다시 
			Insert_Node(&(*tree)->right, child);
		}
	}
	else if ((*tree)->data > child->data) {		// root의 값 보다 자식의 값이 작을 경우
		if ((*tree)->left == NULL) {	// root의 왼쪽 자식이 없을 경우
			(*tree)->left = child;
		}
		else {							// 있을 경우
			Insert_Node(&(*tree)->left, child);
		}
	}
}

Node* Delete_Node(Node* tree, Node* parent, int target) {

	Node* del_node = NULL;

	// 타겟 탐색
	if (tree == NULL) {
		return NULL;
	}

	if (tree->data < target) {
		del_node = Delete_Node(tree->right, tree, target);
	}
	else if (tree->data > target) {
		del_node = Delete_Node(tree->left, tree, target);
	}
	else {	// 타겟 찾음 ( 3가지 노드 종류에 따라 삭제 수행)

		if (tree->left == NULL && tree->right == NULL) {	// 타겟이 앞 노드인 경우
			if (parent->right == tree) {
				parent->right = NULL;
			}
			else {
				parent->left = NULL;
			}
		}

		else if (tree->left != NULL && tree->right != NULL) {	// 양쪽 자식이 있을 경우

			// 오른쪽 자식트리에서 '최솟값'가진 노드를 탐색
			Node* minnode = SearchMinNode(tree->right);
			del_node = Delete_Node(tree, NULL, minnode->data); // 최솟값 노드를 제거
			tree->data = minnode->data;
		}
		else{	// 외자식이 있는 경우

			Node* tempTree = NULL;

			if (tree->right != NULL) {	//어느 쪽 자식트리인지 확인
				tempTree = tree->right;
			}
			else {
				tempTree = tree->left;
			}


			//타겟의 자식트리를 자신의 부모에게 이어준다.
			if (parent->right == tree) {
				parent->right = tempTree;
			}
			else {
				parent->left = tempTree;
			}
		}

		return del_node;

	}

}

int main() {

	Node* root = NULL;

	Insert_Node(&root, 5);







}