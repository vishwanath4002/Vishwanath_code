#include<stdio.h>
#include<stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;    
};

struct bst *root=NULL;

struct bst* createnode(int key)
{
    struct bst* node=malloc(sizeof(struct bst));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct bst* insert(struct bst* root, int key)
{
    if(root==NULL)
    {
        return createnode(key);
    }
    else if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=insert(root->right,key);
    }
    else if(key==root->data)
    {
        printf("Node cannot be added.");
    }
    return root;
}

struct bst* predecessor(struct bst* root)
{
    struct bst* p=root->left;
    while(p!=NULL)
    {
        p=p->right;
    }
    return p;
}
struct bst* delete(struct bst* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left=delete(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=delete(root->right,key);
    }
    else if(key==root->data)
    {
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        struct bst* prev=predecessor(root);
        root->data=prev->data;
        root->left=delete(root->left,prev->data);
        return root;
    }
    else
    {
        printf("Value not found.");
    }
}
void inorder(struct bst* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void main()
{
    int ch, key;
    do
    {
        printf("1.Insert element\n2.Deletion\n3.Inorder traversal\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&key);
                root=insert(root,key);
                break;
            
            case 2:
                printf("\nEnter the value to be deleted : ");
                scanf("%d",&key);
                root=delete(root,key);
                break;
            
            case 3:
                printf("\nThe inorder traversal is : ");
                inorder(root);
                break;
            
            case 4:
                break;
            
            default:
                printf("Invalid choice.");
                break;
        }
        printf("\n");
    } while (ch!=4);
}