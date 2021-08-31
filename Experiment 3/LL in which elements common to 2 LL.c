//Program to create a LL which contains elements common to 2 LL.
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
struct node *commonl(struct node *, struct node *,struct node *);
int check(struct node *start,int data);
int main(){
   struct node *start1=NULL,*start2=NULL, *common;
      printf("\nEnter List 1: ");
      start1=create_list(start1);
      printf("\nEnter List 2: ");
      start2=create_list(start2);
      printf("\nList 1 is: ");
      display(start1);
      printf("\nList 2 is : ");
      display(start2);
      printf("Displaying the List containing common elements from List 1 and 2:");
      common=commonl(start1,start2,common);
      display(common);
}
//create a list function
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
//display list function
void display(struct node *start){
	struct node *p;
    	if(start==NULL){
		  printf("List is Empty!");
		  return;
	    }
	    p=start;
    	printf("\nList is:\n");
	   while(p!=NULL){
		  printf("%d\n",p->info);
	   	  p=p->link;
	   }
	   printf("\n\n");
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
//common function to find common elements from both the lists
struct node *commonl(struct node *start1, struct node* start2,struct node *start3)
{
	struct node *p,*q;
	p=start1,q=start2;
	start3=NULL;
	while(p!=NULL)
	{
		q=start2;
		while(q!=NULL)
		{
			if(p->info==q->info&&check(start3,p->info))
			{
				if(start3==NULL)
				{				
					start3=addatbeg(start3,p->info);
				}
				else
				{
					start3=addatend(start3,p->info);
				}
			}
			q=q->link;
		}
		p=p->link;
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
