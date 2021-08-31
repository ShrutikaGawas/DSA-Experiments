//Heap Sort
#include<stdio.h>
#define MAX 100
void heapsort(int arr[],int n);
void buildheap(int arr[],int n);
int delroot(int arr[],int *size);
void restoredown(int arr[],int i,int size);
void display(int arr[],int n);
main(){
	int i,n,arr[MAX];
    printf("Enter number of elements:\n");
	scanf("%d",&n);
	printf("Enter elements: \n");
    for(i=1;i<=n;i++)
	  scanf("%d",&arr[i]);
	heapsort(arr,n);
	printf("List sorted by Heap Sort is: \n");
	display(arr,n);
}
void heapsort(int arr[],int size){
	int max;
	buildheap(arr,size);
	printf("\nHeap is: ");
	display(arr,size);
	while(size>1){
		max=delroot(arr,&size);
		arr[size+1]=max;
	}
}

int delroot(int arr[],int *size){
	int max=arr[1];
	arr[1]=arr[*size];
	(*size)--;
	restoredown(arr,1,*size);
	return max;
}

void buildheap(int arr[],int size){
	int i;
	for(i=size/2;i>=1;i--)
	 restoredown(arr,i,size);
}

void restoredown(int arr[],int i,int size){
	int left=2*i,right=left+1;
	int num=arr[i];
	while(right<=size){
		if(num>=arr[left] && num>=arr[right]){
			arr[i]=num;
			return;
		}
		else if(arr[left] > arr[right]){
			arr[i]=arr[left];
			i=left;
		}
		else{
			arr[i]=arr[right];
			i=right;
		}
		left=2*i;
		right=left+1;
	}
	if(left==size && num<arr[left]){
		arr[i]=arr[left];
		i=left;
	}
	arr[i]=num;
	printf("%d\n",arr[i]);
}
void display(int arr[],int n){
	int i;
	for(i=1;i<=n;i++)
	 printf("%d ",arr[i]);
	printf("\n");
}
