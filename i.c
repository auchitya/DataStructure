#include<stdio.h>
void isort(int *a,int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        t=a[i];
	    j=i-1;
	    while(j>=0 && a[j]>t) 
        {
            a[j+1]=a[j];
            j--;
        }
	    a[j+1]=t;
    }
}
void merge(int*a , int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;  
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
    i = 0;                   
    j = 0;                    
    k = l;                     
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k++] = L[i++]; 
             
        } 
        else
        { 
            a[k++] = R[j++];             
        } 
    }       
    while (i < n1) 
    { 
        a[k++] = L[i++]; 

    }       
    while (j < n2) 
    { 
        a[k++] = R[j++];        
    } 
} 
void msort(int *a, int l, int r) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
        msort(a, l, m); 
        msort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 

}
void main()
{
    int n;              
    printf("n enter the size of array ");
    scanf("%d",&n);
    int a[n];              
    printf("\n enter the elements of the array ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n To sort the given array using the following method enter\n1- insertion sort \n2-Mergesort ");
    int wish;
    scanf("%d",&wish);
    switch(wish)
    {
        case 1: { 
                    isort(a,n);
                    printf("\n the array in ascending order : ");

                    for(int k=0;k<n;k++)
                        printf("%d ",a[k]);

                    break;
                }
        case 2:  { 
                    msort(a,0,n);
                    printf("\n the array in ascending order : ");

                    for(int k=0;k<n;k++)
                        printf("%d ",a[k]);

                    break;
                }
        default: printf("\n Invalid choice");
    }
}
