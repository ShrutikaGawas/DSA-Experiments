//Program to merge two lists into a single list.
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
void merge(struct node *,struct node *,struct node **);
int main(){
   struct node *start1=NULL,*start2=NULL, *start3=NULL;
      printf("\nEnter List 1: ");
      start1=create_list(start1);
      printf("\nEnter List 2: ");
      start2=create_list(start2);
      printf("\nList 1 is: ");
      merge(start1,start2,&start3);
      display(start1);
      printf("\nList 2 is : ");
      display(start2);
      printf("\nMerged List is : ");
      display(start3);
}
struct node *create_list(struct node*start){
	  int i,n,data;
	  printf("\nEnter number of nodes:");
	  scanf("%d",&n);
	  start=NULL;
	  if(n==0)
	  return start;
	  printf("\nEnter the elements to be inserted:");
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
    	printf("\n");
	   while(p!=NULL){
		  printf("%d\n",p->info);
	   	  p=p->link;
	   }
	   printf("\n");
}
//add at beginning function
struct node *addatbeg(struct node *start,int data){
	struct node *tmp;
	    tmp=(struct node*)malloc(sizeof(struct node));
	    tmp->info=data;
	    tmp->link=start;
	    start=tmp;
	    return start;
}
//add at the end function
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
//merge function
void merge(struct node *start1,struct node*start2,struct node **start3)
{
	struct node *p1=start1,*p2=start2,*p3=start3;
	while(p1!=NULL)                    //traversal of first list
	{
		if(*start3==NULL)
			  *start3 = addatbeg(*start3,p1->info);    //add elements from first list into third
		else
			  *start3= addatend(*start3,p1->info);
	    p1=p1->link;
	}
	while(p2!=NULL)                        //traversal of second list
	{
	    *start3= addatend(*start3,p2->info);     //add elements from second list into third.
	     p2=p2->link;
	}
	
}
