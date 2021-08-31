//Program of Matrix Multiplication.
#include<stdio.h>
main()
{
    int a[3][3],b[3][3],d[3][3],r,c,k;
    printf("\n ENTER THE VALUES OF MAT 'A':");
    for(r=0;r<3;r++)
    {
        for(c=0;c<3;c++)
        {
         scanf("%d",&a[r][c]);
        }
    }
    printf("\n ENTER THE VALUES OF MAT 'B':");
    for(r=0;r<3;r++)
    {
        for(c=0;c<3;c++)
        {
         scanf("%d",&b[r][c]);
        }
    }
    printf("\n\nMatrix A:") ;
    for(r=0;r<3;r++)
    {  printf("\n");
        for(c=0;c<3;c++)
        {
            printf(" %d",a[r][c]);
        }
    }
    printf("\n\nMATRIX B:");
    for(r=0;r<3;r++)
    {  printf("\n");
        for(c=0;c<3;c++)
        {
            printf(" %d",b[r][c]);
        }
    }
    for(r=0;r<3;r++)              //for loop to multiply the 2 MATS
   {
        for(c=0;c<3;c++)
        {   
             d[r][c]=0;
            for(k=0;k<3;k++)
            {
                d[r][c]=d[r][c]+a[r][k]*b[k][c];
            }
        }
   }
    printf("\n\n");
    printf("MATRIX C:");
    for(r=0;r<3;r++)
    { printf("\n");
        for(c=0;c<3;c++)
        {
            printf(" %d",d[r][c]);
        }
    }
}
