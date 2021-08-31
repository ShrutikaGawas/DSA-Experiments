//Radix Sort(
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*start=NULL;
void radixsort();
int largedig();
int digit(int number,int k);
main(){
	struct node *tmp,*q;
	int i,n,item;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&item);
		//Inserting elements in the linked list
	  tmp=malloc(sizeof(struct node));
	  tmp->info=item;
	  tmp->link=NULL;
	  if(start==NULL)    //Inserting first element
	   start=tmp;
	  else{
	    q=start;
		while(q->link!=NULL)
		  q=q->link;
		q->link=tmp;
	  }		
	}
	radixsort();
	printf("List sorted by using Radix Sort is: \n");
	q=start;
	while(q!=NULL){
		printf("%d ",q->info);
		q=q->link;
	}
	printf("\n");
}
void radixsort(){
	int i,k,d,l,m;
	struct node *p,*r[10],*f[10];
	l=1,m=largedig(start);
	for(k=l;k<=m;k++){
		//Make all queues empty at the beginning of each pass
		for(i=0;i<=9;i++){
			r[i]=NULL;
			f[i]=NULL;
		}
		for(p=start;p!=NULL;p=p->link){
			d=digit(p->info,k);     //find the kth digit in number
			//add number to queue of digit
			if(f[d]==NULL)
			   f[d]=p;
			else
			   r[d]->link=p;
			r[d]=p;
		}
		//join all the queues to form new linked lists
		i=0;
		while(f[i]==NULL)
		   i++;
		start=f[i];
		while(i<9){
			if(r[i+1]!=NULL)
			  r[i]->link=f[i+1];
			else
			  r[i+1]=r[i];
			i++;
		}
		r[9]->link=NULL;
    }
}
//function finds number of digits in the largest element of the list
int largedig(){
	struct node *p=start;
	int large=0,ndig=0;
	//find largest element
	while(p!=NULL){
		if(p->info>large)
		   large=p->info;
		p=p->link;
	}
	//find the number of digits in largest element
	while(large!=0){
		ndig++;
		large=large/10;
	}
	return(ndig);
}
//function returns Kth digit of number
int digit(int number,int k){
	int digit,i;
	for(i=1;i<=k;i++){
		digit=number%10;
		number=number/10;
	}
	return digit;
}
