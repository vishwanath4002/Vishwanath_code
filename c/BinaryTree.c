#include<stdio.h>
#include<stdlib.h>
struct Node {
	int key;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int key) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}
struct Node* insert(struct Node* root, int key) 
{
	if (root == NULL) {
		return createNode(key);
	}
	struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100); // Assuming a maximum of 100 nodes
	int front = -1;
	int rear = -1;

	queue[++rear] = root;

	while (front != rear) {
		struct Node* temp = queue[++front];

		if (temp->left == NULL) {
			temp->left = createNode(key);
			free(queue);
			return root;
		} else {
			queue[++rear] = temp->left;
		}
		if (temp->right == NULL) {
			temp->right = createNode(key);
			free(queue);
			return root;
		} else {
			queue[++rear] = temp->right;
		}
	}
	free(queue);
	return root;
}
void inorderTraversal(struct Node* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->key);
		inorderTraversal(root->right);
	}
}
void postorderTraversal(struct Node* root) {
	if (root != NULL) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ", root->key);
	}
}
void preorderTraversal(struct Node* root) {
	if (root != NULL) {
		printf("%d ", root->key);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
struct Node* deleteNode(struct Node* root, int key) {
	if (root == NULL) {
		return root;
	}
	if (root->key == key) {
		free(root);
		return NULL;
	}
	struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100); // Assuming a maximum of 100 nodes
	int front = -1, rear = -1;
	queue[++rear] = root;
	while (front != rear) {
		struct Node* temp = queue[++front];
		if (temp->left != NULL && temp->left->key == key) {
			free(temp->left);
			temp->left = NULL;
			break;
		} else {
			queue[++rear] = temp->left;
		}
		if (temp->right != NULL && temp->right->key == key) {
			free(temp->right);
			temp->right = NULL;
			break;
		} else {
			queue[++rear] = temp->right;
		}
	}
	free(queue);
	return root;
}

int main() {
	struct Node* root = NULL;
	int choice, key;
	printf("\n1. Insert into Binary Tree (Level-wise), 2. Delete a specific key from Binary Tree, 3. Inorder Traversal, 4. Postorder Traversal, 5. Preorder Traversal, 6. Exit\n");
	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter the key to insert: ");
				scanf("%d", &key);
				root = insert(root, key);
				printf("Key inserted into the binary tree.\n");
				break;
			case 2:
				printf("Enter the key to delete: ");
				scanf("%d", &key);
				root = deleteNode(root, key);
				printf("Key deleted from the binary tree.\n");
				break;
			case 3:
				printf("Inorder Traversal: ");
				inorderTraversal(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder Traversal: ");
				postorderTraversal(root);
				printf("\n");
				break;
			case 5:
				printf("Preorder Traversal: ");
				preorderTraversal(root);
				printf("\n");
				break;
			case 6:exit(0);
			default:
				printf("Invalid choice. Please enter a valid option.\n");
		}
	}
	return 0;
}