#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create_list(struct node* );
void display(struct node *start );
struct node *concat(struct node *start1,struct node *start2);
struct node *insert(struct node *start,int data);
struct node *insert_s(struct node *start,int data);
int main(){
   struct node *start1=NULL,*start2=NULL;
      printf("\nEnter List 1: ");
      start1=create_list(start1);
      printf("\nEnter List 2: ");
      start2=create_list(start2);
      printf("\nList 1 is: ");
      display(start1);
      printf("\nList 2 is : ");
      display(start2);
      concat(start1,start2);
}
struct node *create_list(struct node*start){
	  int i,n,data;
	  printf("\nEnter number of nodes:");
	  scanf("%d",&n);
	  start=NULL;
	  for(i=1;i<=n;i++){
	  	printf("\nEnter the elements to be inserted:");
	    scanf("%d",&data);
	    start=insert_s(start,data);
	  }
	  return start;
}
//display function
void display(struct node *start){
	struct node *p;
    	if(start==NULL){
		  printf("List is Empty!");
		  return;
	    }
	    p=start;
    	printf("\n");
	   while(p!=NULL){
		  printf("%d\n",p->info);
	   	  p=p->link;
	   }
	   printf("\n");
}

struct node *insert_s(struct node *start,int data){
	 struct node *p,*tmp;
	 tmp=(struct node*)malloc(sizeof(struct node));
	 tmp->info=data;
	 if(start==NULL || data<start->info){             
	 	tmp->link=start;
	    start=tmp;
	    return start;
	 }               	
	 else
	 {
	 	p=start;
	 	while(p->link!=NULL && p->link->info < data)
	 	  p=p->link;
	 	tmp->link=p->link;
	 	p->link=tmp;
	 }
	 return start;	   
}

struct node *insert(struct node *start,int data){
	 struct node *p,*tmp;
	 tmp=(struct node*)malloc(sizeof(struct node));
	 tmp->info=data;
	 if(start==NULL){             
	 	tmp->link=start;
	    start=tmp;
	    return start;
	 }               	
	 else
	 {
	 	p=start;
	 	while(p->link!=NULL)
	 	  p=p->link;
	 	tmp->link=p->link;
	 	p->link=tmp;
	 }
	 return start;	   
}
//concatenate function
struct node *concat(struct node *start1,struct node *start2){
	struct node *start3;
	start3=NULL;
	while(start1!=NULL && start2!=NULL){
		if(start1->info <start2->info){
			start3=insert(start3,start1->info);
			start1=start1->link;
		}
		else if(start1->info > start2->info){
			start3=insert(start3,start2->info);
			start2=start2->link;
		}
		else if(start1->info == start2->info){
			start3=insert(start3,start1->info);
			start1=start1->link;
			start2=start2->link;
		}
	}
	while(start1!=NULL){
		start3=insert(start3,start1->info);
		start1=start1->link;
	}
	while(start2!=NULL){
		start3=insert(start3,start2->info);
		start2=start2->link;
	}
	printf("\nConcatenated Sorted List is: ");
	display(start3);
}
