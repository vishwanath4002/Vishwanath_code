#include <stdio.h> 
#include <stdlib.h> 

void insert(int tree[], int value, int index)
{ 
    if (tree[index] == 0)
    { 
        tree[index] = value; 
        printf("Node %d inserted successfully.\n", value); 
    }
    else
    {
        printf("Node at index %d is already occupied.\n", index); 
    } 
} 

void inorderTraversal(int tree[], int index, int size)
{ 
    if (index < size && tree[index] != 0)
    { 
        inorderTraversal(tree, 2 * index + 1, size); 
        printf("%d ", tree[index]); 
        inorderTraversal(tree, 2 * index + 2, size); 
    } 
} 
 
void deleteNode(int tree[], int value, int size)
{ 
    for (int i = 0; i < size; i++)
    { 
        if (tree[i] == value)
        { 
            tree[i] = 0; 
            printf("Node %d deleted successfully.\n", value); 
            return; 
        } 
    } 
    printf("Node %d not found in the tree.\n", value); 
} 
 
int main()
{ 
    int MAX_SIZE = 100; 
    int tree[MAX_SIZE]; 
    for (int i = 0; i < MAX_SIZE; i++)
    { 
        tree[i] = 0; 
    } 
    int choice, value; 
    while (1)
    { 
        printf("\nBinary Tree Operations:\n"); 
        printf("1. Insert\n"); 
        printf("2. Inorder Traversal\n"); 
        printf("3. Delete Node\n"); 
        printf("0. Exit\n"); 
        printf("Enter your choice: "); 
        if (scanf("%d", &choice) != 1)
        { 
            // Handle non-numeric input 
            printf("Invalid input. Exiting.\n"); 
            break; 
        }
        switch (choice)
        { 
            case 1: 
                printf("Enter a value to insert: "); 
                scanf("%d", &value); 
 
 
                if (tree[0] == 0)
                { 
                    tree[0] = value; 
                    printf("Node %d inserted as the root.\n", value); 
                }
                else
                { 
                    int index = 0;  // Initialize index for the new node 
                    while (1)
                    { 
                        printf("\nCurrent element %d\nChoose side (0 for left, 1 for right): ", tree[index]); 
                        int side; 
                        scanf("%d", &side); 
                        if (side == 0)
                        { 
                            index = 2 * index + 1; 
                        }
                        else if (side == 1)
                        { 
                            index = 2 * index + 2; 
                        } 

                        if (tree[index] == 0)
                        { 
                            break;  // Exit the loop if the chosen side is unoccupied 
                        } 
                    } 
                    insert(tree, value, index); 
                } 
                break; 

            case 2: 
                printf("Inorder Traversal: "); 
                inorderTraversal(tree, 0, MAX_SIZE); 
                printf("\n"); 
                break; 
 
            case 3: 
                printf("Enter a value to delete: "); 
                scanf("%d", &value); 
                deleteNode(tree, value, MAX_SIZE); 
                break; 
 
            case 0: 
                exit(0); 
 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } 
    return 0; 
}