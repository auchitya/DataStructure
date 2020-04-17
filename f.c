#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left,*right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data :");
    scanf("%d",&x);
    if(x==0)
    {
        return 0;
    }
    newnode->data=x;
    printf("enter the left child of %d",x);
    newnode->left=create();
    printf("enter the right child of %d",x);
    newnode->right=create();
    return newnode;
}
int nnodes(struct node *root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        return(1+ nnodes(root->left) + nnodes(root->right)); 
    }
    
}

void main()
{
    struct node *root;
    root=0;
    root=create();
    printf("\nnumber of nodes=%d", nnodes(root));
}