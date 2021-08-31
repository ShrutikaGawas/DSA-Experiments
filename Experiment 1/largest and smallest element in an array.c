//Program to find the largest and the smallest element in a 1D Array.
#include<stdio.h>
main()
{
    int x[10],i,j,y,count=0,n;
    printf("HOW MANY VALUES TO BE ENTERED:");
    scanf("%d",&n);
    printf("ENTER THE VALUES:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    int max=x[0];                                                 //initiate min and max to arr[0].
    int min=x[0];
    for(i=0;i<n;i++)
    { 
        if(x[i]>max)                                    //compare if every element is greater than max.
           max=x[i];
        if(x[i]<min)                             //compare if every element is lesser than min.
            min=x[i];
    }
    printf("\n The MAXIMUM value is %d",max);
    printf("\n The MINIMUM value is %d",min);
}
