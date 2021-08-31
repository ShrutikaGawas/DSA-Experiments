//Program to Add 2 Matrices.
#include<stdio.h>
main()
{
    int x[2][2],y[2][2],z[2][2],r,c,n,m;
     printf("Enter the no. of rows and columns of the Matrix:");
    scanf("%d%d",&n,&m);
    printf("\nENTER THE VALUES OF MATRIX 'X':");
     for(r=0;r<n;r++)
    {
        for(c=0;c<m;c++)
        {
            scanf("%d",&x[r][c]);
        }
    }
     printf("\nENTER THE VALUES OF MATRIX 'Y':");
      for(r=0;r<n;r++)
    {
        for(c=0;c<m;c++)
        {
          scanf("%d",&y[r][c]);
        }
    }
    printf("\n\n MATRIX X:");           //for loop to display MAT X
    for(r=0;r<n;r++)
    {
    	printf("\n\t\t");
        for(c=0;c<m;c++)
        {
          printf("%d ",x[r][c]);
        }
    }
    printf("\n\n MATRIX Y:");          //for loop to display MAT Y
    for(r=0;r<n;r++)
    {
    	printf("\n\t\t");
        for(c=0;c<m;c++)
        {
          printf("%d ",y[r][c]);
        }
    }
    for(r=0;r<n;r++)                                              //for loop to ADD the elements of 2 Mats
    {
        for(c=0;c<m;c++)
        {
           z[r][c]=x[r][c]+y[r][c];
        }
    }
    printf("\n\n ADDITION OF MAT 'X' AND MAT 'Y':");
    for(r=0;r<n;r++)
    { 
         printf("\n\t\t");
        for(c=0;c<m;c++)
        {
            printf("%d ",z[r][c]);
        }
    }
}
