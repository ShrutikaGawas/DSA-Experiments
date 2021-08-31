//Program to find duplicate elements in a SLL.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create_list(struct node*);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
void display(struct node *);
void duplicate(struct node **);
int main(){
   struct node *start1=NULL;
      printf("\nEnter List 1: ");
      start1=create_list(start1);
      printf("\nList 1 is: ");
      display(start1);
      printf("\nDuplicate Elements are:");
      duplicate(&start1);
}
//create a list funcion
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
    	printf("\nList is:\n");
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
//duplicate function to find the duplicate elements in a function
void duplicate(struct node **head)
{
    struct node *p, *q, *prev, *temp;
    p = q = prev = *head;                                          //initialise p, q, prev to the head of the list.
    q = q->link;                                                        //increment q.
    while (p != NULL)                                                     //traversal of list 
    {
        while (q != NULL && q->info != p->info)                     //if q and p aren’t duplicates
        {
             prev = q;
             q = q->link;
        }
        if (q == NULL)                                                               //if q null then incr. p
        {
            p = p->link;
            if (p != NULL)
            {
                q = p->link;
            }
        }
        else if (q->info == p->info)                           //finding duplicates
        {
        	  printf("\n%d",p->info);
             prev->link = q->link;
             temp = q;
             q = q->link;
             free(temp);
        }
    }
}
