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
int leafcount(struct node *root) 
{ 
  if(root == NULL)        
    return 0; 
  if(root->left == NULL && root->right==NULL)       
    return 1;             
  else 
    return leafcount(root->left) + leafcount(root->right);       
} 
int nonleafnode(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    else if (root->left==NULL&&root->right==NULL)
    {
        return 0;
    }
    else
    {
        return(1+nonleafnode(root->left) + nonleafnode(root->right));
    }
}  
void main()
{
    struct node *root;
    root=0;
    root=create();
    printf("\nnumber of leaf nodes=%d",leafcount(root));
    printf("\nnumber of non leaf nodes=%d",nonleafnode(root));
}