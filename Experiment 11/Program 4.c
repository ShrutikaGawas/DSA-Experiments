//Merge Sort(Bottom-Up approach)
#include<stdio.h>
#define MAX 100
void mergesort(int arr[],int n);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void mergepass(int arr[],int temp[],int size,int n);
void copy(int arr[],int temp[],int n);
main(){
	int arr[MAX],i,n;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
	printf("Enter elements: \n");
    for(i=0;i<n;i++)
	 scanf("%d",&arr[i]);
    mergesort(arr,n);
	printf("\nList sorted by Merge Sort is: ");
	for(i=0;i<n;i++)
	 printf("%d ",arr[i]);
	printf("\n");
}
void mergesort(int arr[],int n){
	int size=1;
	int temp[MAX];
	while(size<n){
		mergepass(arr,temp,size,n);
		size=size*2;
	}
}
void mergepass(int arr[],int temp[],int size,int n){
	int i,low1,low2,up1,up2;
	low1=0;
	while(low1+size <n){
		up1=low1+size-1;
		low2=low1+size;
		up2=low2+size-1;
		if(up2 >= n)   //if len of last sublist is less than size
		  up2=n-1;
		merge(arr,temp,low1,up1,low2,up2);
		low1=up2+1; //take next 2 sublists for merging
	}
	for(i=low1;i<=n-1;i++)
	  temp[i]=arr[i];              //if any sublist is left
	copy(arr,temp,n);
}
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2){
	int i=low1;
	int j=low2;
	int k=low1;
	while(i<=up1 && j<=up2){
		if(arr[i]>=arr[j])
		   temp[k++]=arr[i++];
	    else
	       temp[k++]=arr[j++];
	}
	while(i<=up1)
	  temp[k++]=arr[i++];
	while(j<=up2)
	  temp[k++]=arr[j++];
}
void copy(int arr[],int temp[],int n){
	int i;
	for(i=0;i<n;i++)
	  arr[i]=temp[i];
}

