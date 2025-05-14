#include <stdio.h>
#include <stdlib.h>

struct bst 
{
    int data;
    struct bst *left;
    struct bst *right;
};

struct bst* create_bst(int data) 
{
    struct bst *new_node = (struct bst *)malloc(sizeof(struct bst));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct bst* insert_bst(struct bst *root, int data) 
{
    if (root == NULL) 
    {
        return create_bst(data);
    }
    if (data < root->data) 
    {
        root->left = insert_bst(root->left, data);
    }
    else if (data > root->data) 
    {
        root->right = insert_bst(root->right, data);
    }
    return root;
}

void inorder(struct bst *root) 
{
    if (root == NULL) 
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct bst* search(struct bst *root, int key)
{
    if (root==NULL)
    {
       return NULL;
    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else if(root->data<key)
    {
        return search(root->right,key);
    }
    else
    {
        return root;
    }
}
struct bst *predecessor(struct bst *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
struct bst *sucessor(struct bst *root)
{
    root=root->right;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
struct bst* delete(struct bst *root,int key)
{   
    struct bst *pre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data>key)
    {
        root->left = delete(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=delete(root->right,key); 
    }    
    else 
    {
       pre=predecessor(root);
       root->data=pre->data;
       root->left=delete(root->left,pre->data);
    }
    return root;
}

int main() 
{
    struct bst *root = NULL;
    int data;
    int s;
    while (1) 
    {
        printf("\n1.New value\n2.Deletion\n3.Traversal\n4.Search specified node\n5.Exit\n");
        printf("Enter your choice=");
        scanf("%d", &s);
        switch (s) 
        {
            case 1:
                printf("Enter the data to be inserted in the binary search tree=");
                scanf("%d", &data);
                root = insert_bst(root, data);
                break;
            case 2:
                printf("Enter the data to be deleted in the binary search tree=");
                scanf("%d", &data);
                root = delete(root, data);  
            case 3:
                printf("The binary search tree (in-order)=");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the data to be searched in the binary search tree=");
                scanf("%d", &data);
                if(search(root,data))
                    {
                        printf("Element found");
                    }
                else
                    {
                        printf("Element not found");
                    }
                break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}