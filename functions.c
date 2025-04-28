#include "functions.h"

int getIntNumber()
{
    int n;
    while (1) {
        if (scanf_s("%d", &n) != 0) {
            if ((getchar()) != '\n' || n > INT_MAX || n < INT_MIN) {
                printf("Error: enter the correct number!\n");
                while ((getchar()) != '\n')
                    continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Error: enter the correct number!\n");
            while ((getchar()) != '\n')
                continue;
        }
    }
    return n;
}

BinaryTree* createBinaryTree(int data) {
	BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (!tree) {
		perror("MEMORY ALLOCATION ERROR!");
		return NULL;
	}
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

void showBinaryTree(BinaryTree* tree, int level) {
	if (tree) {
		showBinaryTree(tree->right, level + 1);
		for (int i = 0; i < level; ++i) printf("\t");
		printf("%d\n", tree->data);
		showBinaryTree(tree->left, level + 1);
	}
}

int findNode(BinaryTree* tree, int data) {
    if (tree == NULL) return 0;
    if (tree->data == data) return 1; 
    return findNode(tree->left, data) || findNode(tree->right, data);
}

void insertNode(BinaryTree* tree, int data) {
    if (tree == NULL) return;



    BinaryTree* current = tree;
    while (1) {
        printf("Current node: %d\n", current->data);
        printf("Where to insert %d? (l - left, r - right): ", data);

        char direction;
        scanf_s(" %c", &direction); 

        if (direction == 'l') {
            if (current->left == NULL) {
                current->left = createBinaryTree(data);
                printf("Inserted %d to the left of %d\n", data, current->data);
                return;
            }
            else {
                current = current->left;
            }
        }
        else if (direction == 'r') {
            if (current->right == NULL) {
                current->right = createBinaryTree(data);
                printf("Inserted %d to the right of %d\n", data, current->data);
                return;
            }
            else {
                current = current->right;
            }
        }
        else {
            printf("Invalid input! Please enter 'l' or 'r'.\n");
        }
    }
}

BinaryTree* deleteNode(BinaryTree* tree, int data) {
    if (tree == NULL) return NULL;

    if (tree->data == data) {

        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        }

        if (tree->left == NULL) {
            BinaryTree* temp = tree->right;
            free(tree);
            return temp;
        }

        if (tree->right == NULL) {
            BinaryTree* temp = tree->left;
            free(tree);
            return temp;
        }

        // 
        printf("Cannot delete node with two children.\n");
        return tree;
    }

    tree->left = deleteNode(tree->left, data);
    tree->right = deleteNode(tree->right, data);
    return tree;
}

void deleteNodesByUserInput(BinaryTree* tree) {
    int value;
    char choice;

    do {
        printf("Enter the value of the node to delete: ");
        scanf_s("%d", &value);
        tree = deleteNode(tree, value);

        printf("Do you want to delete another node? (y/n): ");
        scanf_s(" %c", &choice);
    } while (choice == 'y');
}

int isMirror(BinaryTree* tree1, BinaryTree* tree2) {

    if (tree1 == NULL && tree2 == NULL) return 1;

    if (tree1 == NULL || tree2 == NULL) return 0;

    return (tree1->data == tree2->data) &&
        isMirror(tree1->left, tree2->right) &&
        isMirror(tree1->right, tree2->left);
}

int isSymmetric(BinaryTree* tree) {
    if (tree == NULL) return 1; 
    return isMirror(tree->left, tree->right);
}


