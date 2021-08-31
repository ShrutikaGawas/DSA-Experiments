//Program to create a List containing all elements from 2 Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create_list(struct node* );
void display(struct node * );
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *unionl(struct node *start1,struct node *start2,struct node *start3);
int check(struct node *,int data);
int main(){
   struct node *start1=NULL,*start2=NULL,*start3;
      printf("\nEnter List 1: ");
      start1=create_list(start1);
      printf("\nEnter List 2: ");
      start2=create_list(start2);
      printf("\nList 1 is: ");
      display(start1);
      printf("\nList 2 is : ");
      display(start2);
      start3=unionl(start1,start2,start3);
      printf("\nDisplaying List containing all elements of 2 Lists:\n");
      display(start3);
    
}
//create list function.
struct node *create_list(struct node*start){
	  int i,n,data;
	  printf("\nEnter number of nodes:");
	  scanf("%d",&n);
	  start=NULL;
	  if(n==0)
	  return start;
	  printf("Enter the elements to be inserted:");
	  scanf("%d",&data);
	  start=addatbeg(start,data);
	  for(i=2;i<=n;i++){
	    scanf("%d",&data);
	    start=addatend(start,data);
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
    	printf("List is:\n");
	   while(p!=NULL){
		  printf("%d\n",p->info);
	   	  p=p->link;
	   }
	   printf("\n");
}
//add at begining function
struct node *addatbeg(struct node *start,int data){
	struct node *tmp;
	    tmp=(struct node*)malloc(sizeof(struct node));
	    tmp->info=data;
	    tmp->link=start;
	    start=tmp;
	    return start;
}
//add at end function
struct node *addatend(struct node *start,int data){
	struct node *p,*tmp;
	    tmp=(struct node*)malloc(sizeof(struct node));
	    tmp->info=data;
	    p=start;
	   while(p->link!=NULL)
	      p=p->link;
	   p->link=tmp;
	   tmp->link=NULL;
	   return start;
}
//find union function to store items from both lists and ignore duplicates
struct node *unionl(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *p1=start1,*p2=start2;
	start3=NULL;
	while(p1!=NULL)
	{
		if(check(start3,p1->info))
		{
			if(start3==NULL)
				start3=addatbeg(start3,p1->info);
			else
				start3=addatend(start3,p1->info);
		}
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(check(start3,p2->info))
		{
			if(start3==NULL)
				start3=addatbeg(start3,p2->info);
			else
				start3=addatend(start3,p2->info);
		}
		p2=p2->link;
	}
	return start3;
}
int check(struct node *start,int data)
{
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->info==data)
			return 0;
		p=p->link;
	}
	return 1;
}
