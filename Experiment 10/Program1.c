#include<stdio.h>
#define MAX 50
int Linearsearch(int arr[],int n,int item);
int Binarysearch(int arr[],int size,int item);
int main(){
	int i,n,item,arr[MAX],index,size,choice;
    while(1){
    	printf("\n\n1.Linear Search: ");
    	printf("\n2.Binary Search");
    	printf("\n3.Exit");
    	printf("\nEnter your choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1: 
    		       printf("Enter number of elements:\n");
	               scanf("%d",&n);
	               printf("Enter elements: \n");
                   for(i=0;i<n;i++)
	               scanf("%d",&arr[i]);
                   printf("Enter item to be searched: \n");
                   scanf("%d",&item);
    		       index=Linearsearch(arr,n,item);
                   if(index==-1)
				     printf("%d is not found\n",item);
				   else
				     printf("%d is found at position %d",item,index+1);
			       break;
		   case 2:
		          printf("Enter number of elements:\n");
	               scanf("%d",&size);
	               printf("Enter elements(in sorted order): \n");
                   for(i=0;i<size;i++)
	               scanf("%d",&arr[i]);
                   printf("Enter item to be searched: \n");
                   scanf("%d",&item);
    		       index=Binarysearch(arr,size,item);
                   if(index==-1)
				     printf("%d is not found\n",item);
				   else
				     printf("%d is found at position %d",item,index+1);
			       break;   
		   case 3:
		          exit(1);
				  break;
		   default:
		           printf("\nInvalid Input");	
		}
    }
}
int Linearsearch(int arr[],int n,int item){  //item to be searched compared with each element one by one
	int i=0;
	while(i<n && item!=arr[i])    
	  i++;                   
	if(i<n)
	 return i;               //returns location of the item if found
	else
	return -1;           //else returns 1
}

int Binarysearch(int arr[],int size,int item){
	int low=0,up=size-1,mid;
	while(low<=up){            
		mid=(low+up)/2;
		if(item>arr[mid])             //search in right half
		  low=mid+1;
		else if(item<arr[mid])        //search in left half
		  up=mid-1;
		else
		  return mid;               //if search successfull position returned
	}
	return -1;             //else -1 returned
}
