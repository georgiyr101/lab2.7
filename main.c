#include "functions.h"

int main() {

	printf("\nMenu:\n");
	printf("1. Create tree\n");
	printf("2. Insert node\n");
	printf("3. Delete node\n");
	printf("4. Print tree\n");
	printf("5. Check is tree symmetric\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");

	BinaryTree* tree = NULL;
	
	while (1) {
		char task = _getch();

		if (task == '1') {
			printf("Enter value of root: ");
			int root = getIntNumber();
			tree = createBinaryTree(root);
		}
		else if (task == '2') {
			printf("Enter value of node: ");
			int node = getIntNumber();
			insertNode(tree, node);
		}
		else if (task == '3') {
			deleteNodesByUserInput(tree);
		}
		else if (task == '4') showBinaryTree(tree, 0);
		else if (task == '5') {
			if (isSymmetric(tree)) {
				printf("The binary tree is symmetric.\n");
			}
			else {
				printf("The binary tree is not symmetric.\n");
			}
		}
		else if (task == '6') break;
		puts(" ");
	}
	
	return 0;
}