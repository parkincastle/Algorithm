#include <stdio.h>
#include <stdlib.h>

typedef struct _node {    // ���� ����Ʈ�� ��� ����ü
	struct _node* right;    // ������ ����� �ּҸ� ������ ������
	struct _node* left;		// ���� ����� �ּҸ� ������ ������
	int data;             // �����͸� ������ ���
} Node;

Node* Serching_Node(Node* tree, int target) {
	if (tree == NULL) {
		printf("Ʈ���� �����ϴ�.");
		return 0;
	}
	if (tree->data == target) {
		printf("Ž�� ����");
	}
	else if (tree->data < target) {	// ���ο� �����Ͱ� �� Ŭ ��
		return Serching_Node(tree->right, target);
	}
	else {							// ���ο� �����Ͱ� �� ���� ��
		return Serching_Node(tree->left, target);
	}
}

void Insert_Node(Node** tree, Node* child) {

	if ((*tree)->data < child->data) {			// root�� �� ���� �ڽ��� ���� ū ���
		if ((*tree)->right == NULL) {	// root�� ������ �ڽ��� ���� ���
			(*tree)->right = child;
		}
		else{							// root�� �ڽ��� ������� �ٽ� 
			Insert_Node(&(*tree)->right, child);
		}
	}
	else if ((*tree)->data > child->data) {		// root�� �� ���� �ڽ��� ���� ���� ���
		if ((*tree)->left == NULL) {	// root�� ���� �ڽ��� ���� ���
			(*tree)->left = child;
		}
		else {							// ���� ���
			Insert_Node(&(*tree)->left, child);
		}
	}
}

Node* Delete_Node(Node* tree, Node* parent, int target) {

	Node* del_node = NULL;

	// Ÿ�� Ž��
	if (tree == NULL) {
		return NULL;
	}

	if (tree->data < target) {
		del_node = Delete_Node(tree->right, tree, target);
	}
	else if (tree->data > target) {
		del_node = Delete_Node(tree->left, tree, target);
	}
	else {	// Ÿ�� ã�� ( 3���� ��� ������ ���� ���� ����)

		if (tree->left == NULL && tree->right == NULL) {	// Ÿ���� �� ����� ���
			if (parent->right == tree) {
				parent->right = NULL;
			}
			else {
				parent->left = NULL;
			}
		}

		else if (tree->left != NULL && tree->right != NULL) {	// ���� �ڽ��� ���� ���

			// ������ �ڽ�Ʈ������ '�ּڰ�'���� ��带 Ž��
			Node* minnode = SearchMinNode(tree->right);
			del_node = Delete_Node(tree, NULL, minnode->data); // �ּڰ� ��带 ����
			tree->data = minnode->data;
		}
		else{	// ���ڽ��� �ִ� ���

			Node* tempTree = NULL;

			if (tree->right != NULL) {	//��� �� �ڽ�Ʈ������ Ȯ��
				tempTree = tree->right;
			}
			else {
				tempTree = tree->left;
			}


			//Ÿ���� �ڽ�Ʈ���� �ڽ��� �θ𿡰� �̾��ش�.
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