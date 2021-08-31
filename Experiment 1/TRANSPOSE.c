//Program to find Transpose of a Matrix.
#include<stdio.h>
main()
{
    int x[3][3],r,c;
    printf("\n ENTER THE VALUES:");
    for(r=0;r<3;r++)
    {
        for(c=0;c<3;c++)
        {
          scanf("%d",&x[r][c]);
        }
    }
    printf("\n The Matrix:");
    for(r=0;r<3;r++)
    {
	    printf("\n");
        for(c=0;c<3;c++)
        {
         printf(" %d",x[r][c]);
        }
    }
   printf("\n\n");
   printf("\n Transpose of Matrix:");
   for(r=0;r<3;r++)
   {
      printf("   \n");
      for(c=0;c<3;c++)
      {
	    printf(" %d",x[c][r]);
      }
   }
}
