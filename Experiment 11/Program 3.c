//Shell Sort(1st compares elements far apart and then closer)
#include<stdio.h>
#define MAX 100
main(){
	int arr[MAX],i,j,k,n,incr;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
	printf("Enter elements: \n");
    for(i=0;i<n;i++)
	 scanf("%d",&arr[i]);
	printf("Enter MAX. increment(odd value): ");
	scanf("%d",&incr);
	while(incr>=1){        //sorting starts
		for(i=incr;i<n;i++){          
			k=arr[i];                
			for(j=i-incr;j>=0 && k<arr[j];j=j-incr)  //insertion sort algo 
			   arr[j+incr]=arr[j];
			arr[j+incr]=k;    
		}
		incr=incr-2; //incr decreased by 2
	}
	printf("\nList sorted by Shell Sort is: ");
	for(i=0;i<n;i++)
	 printf("%d ",arr[i]);
	printf("\n");
}
