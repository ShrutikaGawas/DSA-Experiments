//Program to search elements in a 1D Array.
#include<stdio.h>
main()
{
    int x[10],i,j,n,y,count=0;
     printf("\n HOW MANY VALUES YOU WANT TO ENTER? ");
    scanf("%d",&n);
    printf("ENTER THE VALUES:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\n Enter the Value to be searched:");
    scanf("%d",&y);
    for(i=0;i<n;i++)                                      //for loop to search the number
    {   
        if(y==x[i])
        {
           printf("\n The number is at position %d",i+1);
           count=count+1;
        }
    }
    if(count==0)
    {
      printf("Invalid number");
    }
}
