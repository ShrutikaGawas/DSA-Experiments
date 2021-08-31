//Program to insert elements at a particular position in a 1D array
#include<stdio.h>
main()
{
    int x[10],i,j,n,z,loc,k;
    printf("\n HOW MANY VALUES TO WANT TO ENTER?");
    scanf("%d",&z);
    printf("\n ENTER THE VALUES:");
    for(i=0;i<z;i++)
    {
        scanf("%d",&x[i]);
    }
printf("\n ENTER THE NUMBER TO BE INSERTED:");
scanf("%d",&n);
printf("\n ENTER THE LOCATION TO INSERT THE NUMBER: ");
scanf("%d",&loc);
z++;
for(j=z;j>=loc;j--)
 {
      x[j]=x[j-1];               
 } 
x[loc-1]=n;                                      //put the number at the desired location
for(i=0;i<z;i++)
    printf("\n %d",x[i]);
}
