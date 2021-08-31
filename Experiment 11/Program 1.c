//Bubble,Selection and Insertion Sort.
#include<stdio.h>
#define MAX 100
int main(){
	int i,j,n,k,temp,min,xchanges,arr[MAX],choice;
    while(1){
    	printf("\n\n1.Bubble Sort: ");
    	printf("\n2.Selection Sort:");
    	printf("\n3.Insertion Sort:");
    	printf("\n4.Exit");
    	printf("\nEnter your choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1:  //Bubble Sort(compares each element with adjacent and swaps if out of order)
    		       printf("Enter number of elements:\n");
	               scanf("%d",&n);
	               printf("Enter elements: \n");
                   for(i=0;i<n;i++)
	                scanf("%d",&arr[i]);
                   for(i=0;i<n-1;i++){
                   	   xchanges=0;
                   	   for(j=0;j<n-1-i;j++){
                   		     if(arr[j]<arr[j+1]){
                   		     	 temp=arr[j];
                   	     	     arr[j]=arr[j+1];
                   	     	     arr[j+1]=temp;
                   	     	     xchanges++;
                   		     }   
                   	     }
                   	    if(xchanges==0){        //if list is sorted
                   	     	break;
                   	     }
                   }
                   printf("List is sorted using Bubble Sort: \n");
                   for(i=0;i<n;i++)
                      printf("%d ",arr[i]);
			       break;
		   case 2:   //Selection sort(selects smallest element and keeps in exact place)
		   	       printf("Enter number of elements:\n");
	               scanf("%d",&n);
	               printf("Enter elements: \n");
                   for(i=0;i<n;i++)
	                scanf("%d",&arr[i]);
                   for(i=0;i<n;i++){
                   	  //find index of smallest element
                   	   min=i;
                   	   for(j=i+1;j<n;j++){
                   		    if(arr[min]<arr[j])
                   		      min=j;
                        }                  	      
                   	    if(i!=min){
                   	     	temp=arr[i];
                   	     	arr[i]=arr[min];
                   	     	arr[min]=temp;
                   	     }
				   }
                   printf("List is sorted using Selection Sort: \n");
                   for(i=0;i<n;i++)
                     printf("%d ",arr[i]);
			       break;  
		   case 3: //Insertion Sort(inserts each element at proper position)
		           printf("Enter number of elements:\n");
	               scanf("%d",&n);
	               printf("Enter elements: \n");
                   for(i=0;i<n;i++)
	                scanf("%d",&arr[i]);
                   for(i=1;i<n;i++){
                   	   k=arr[i];         //k is to be inserted at proper place
                   	  for(j=i-1;j>=0 && k>arr[j];j--)
                   		   arr[j+1]=arr[j];
                   	  arr[j+1]=k;	 
                   }
                   printf("List is sorted using Insertion Sort: \n");
                   for(i=0;i<n;i++)
                      printf("%d ",arr[i]);
		           break; 
		   case 4:
		          exit(1);
				  break;
		   default:
		           printf("\nInvalid Input");	
		}
    }
}

