#include<stdio.h>
#include<ctype.h>
#include<string.h>


char stack[20];                     

int top=-1;

int priority(char c)                   
{

    if(c=='^')
    return 3;

    else if(c=='*' || c=='/')
    return 2;

    else if(c=='+'||c=='-')
    return 1;

}


void push(char n)                       
{

    top++;
    stack[top]=n;

}

char pop()                              
{

    if(top>=0)
    {

        char r=stack[top];
        top--;

        return r;

    }
     
}

void main()                     
{

    char infix[20];
    char postfix[20];

    int k=0;

    printf("\nenter the infix expression: ");      
    gets(infix);
    

    for(int i=0;infix[i]!='\0';i++)
    {

        if(infix[i]=='(')
        {

            push('(');
        }

        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {

                postfix[k++]=pop();

            }

            char r=pop();
            
        }

        else if(isdigit(infix[i]))          
        {

            postfix[k++]=infix[i];
        }

        else if(top==-1)               
            push(infix[i]);


        else if(priority(infix[i])>=priority(stack[top]))   
            push(infix[i]);


        else if(priority(infix[i])<priority(stack[top]))    
        {

            while(stack[top]!='(' && top>-1)
            {

                postfix[k++]=pop();
            }

            push(infix[i]);

        }

    }

    while(top>-1)                              
    {
        postfix[k++]=pop();
    }
    printf("\n the Postfix Expression is: ");           

    puts(postfix);
}