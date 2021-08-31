//Program to divide a list into ODD and EVEN Lists depending on info part.
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
void evenodd(struct node *start1, struct node **start2,struct node **start3);

int main(){
   struct node *start1=NULL,*start2=NULL,*start3=NULL;
      start1=create_list(start1);
      evenodd(start1,&start2,&start3);
      printf("\nOriginal List L1 is: ");
      display(start1);
      printf("\nOdd Numbers List  L2 is: ");
      display(start2);
	   printf("\nEven Numbers List L3 is: ");
      display(start3); 
      
}
//create function
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
//finding odd and even elements in evenodd function
void evenodd(struct node *start1,struct node **start2,struct node **start3)
{
	struct node *p1=start1,*p2=start2,*p3=start3;
	while(p1!=NULL)                      //traversal of the list
	{
		if((p1->info)%2 != 0)            //check if element is odd
		{
			if(*start2==NULL)                     //add element in odd list
			  *start2 = addatbeg(*start2,p1->info);
			else
			  *start2 = addatend(*start2,p1->info);   
		}
		else                                     //else element is even
		{
			if(*start3==NULL)                   
			  *start3 = addatbeg(*start3,p1->info);   //add element in even list
			else
			  *start3= addatend(*start3,p1->info);    
		}
        p1=p1->link;
	}
}
