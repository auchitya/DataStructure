#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *newNode(int data){
    struct tree *node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct stack{
    struct tree *t;
    struct stack *next;
};
void push(struct stack **stack,struct tree *tree){
    struct stack *newTree = (struct stack*) malloc (sizeof(struct stack));
    newTree->t = tree;
    newTree->next = (*stack);
    (*stack) = newTree;
}
int isEmpty(struct stack *stack){
    return (stack==NULL);
}
struct tree *pop(struct stack** stack){
    struct stack *temp;
    struct tree *root;
    temp = *stack;
    root = temp->t;
    *stack = temp->next;
    free(temp);
    return root;
}
void InOrder(struct tree *root){
    struct tree* curr = root;
    struct stack *s = NULL;         
    int flag = 0;
    while(!flag){
        if(curr != NULL){
            push(&s,curr);          
            curr = curr->left;     
        }
        else{
            if(!isEmpty(s)){
                curr = pop(&s);     
                printf("%d\t",curr->data);      
                curr = curr->right;         
            }
            else{
                flag = 1;
            }
        }
    }

}
int height(struct tree *root){
    if(root == NULL){
        return 0;
    }
    else{
        int lst;
        int rst;
        lst = height(root->left);
        rst = height(root->right);
        if(rst>lst){
            return rst+1;
        }else{
            return lst+1;
        }
    }
}
int main(){
    struct tree *root = newNode(2);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(1);
    root->right->left = newNode(8);
    printf("InOrder Tree Traversal without recursion:\n");
    InOrder(root);
    printf("\n Height of Tree is = %d\n",height(root));
    return 0;
}