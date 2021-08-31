#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int info;
	struct node *next;
};
struct node *create_list(struct node*start);
void display(struct node *start);
struct node *addtoempty(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *del(struct node *start,int data);
int main(){
	struct node *start=NULL;
	int choice,data,item;
	while(1){
		printf("\n1.Create List\n");
	    printf("2.Display\n");
		printf("3.Add to Empty\n");
	    printf("4.Add at the beginning\n");
		printf("5.Add at the end\n");
		printf("6.Add after the node\n");
		printf("7.Add before the node\n");
		printf("8.Delete\n");
		printf("9.Quit\n\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				start=create_list(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("Enter the elements to be inserted in an empty list:");
				scanf("%d",&data);
				start=addtoempty(start,data);
				break;
			case 4:
				printf("Enter the elements to be inserted at the beginning:");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			case 5:
				printf("Enter the elements to be inserted at the end:");
				scanf("%d",&data);
				start=addatend(start,data);
				break;
			case 6:
				printf("Enter the node to be inserted:");
				scanf("%d",&data);
				printf("Enter the element after which to insert:");
				scanf("%d",&item);
				start=addafter(start,data,item);
				break;
			case 7:
				printf("Enter the element to be inserted:");
				scanf("%d",&data);
				printf("Enter the element before which to insert:");
				scanf("%d",&item);
				start=addbefore(start,data,item);
				break;
			case 8:
			    printf("Enter the element to be deleted:");
				scanf("%d",&data);
				start=del(start,data);
				break;
			case 9:
				exit(1);
			default:
				printf("YOU HAVE GIVEN A WRONG ENTRY!!");
		}
	}
	return 0;
}
struct node *create_list(struct node*start){
	int i,n,data;
	printf("Enter number of nodes to be inserted:");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	return start;
	printf("enter the elements to be inserted:");
	scanf("%d",&data);
	start=addtoempty(start,data);
	for(i=2;i<=n;i++){
		printf("enter the elements to be inserted:");
	    scanf("%d",&data);
	    start=addatend(start,data);
	}
	return start;
}
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
		p=p->next;
	}
	printf("\n\n");
}
struct node *addtoempty(struct node *start,int data){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}
struct node *addatbeg(struct node *start,int data){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
    start->prev=tmp;
    start=tmp;
	return start;
}
struct node *addatend(struct node *start,int data){
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL){
		p=p->next;
	}
	tmp->next=NULL;
	p->next=tmp;
	tmp->prev=p;
	return start;
}
struct node *addbefore(struct node *start,int data,int item){
	struct node *tmp,*p;
	if(start==NULL){
		printf("List is Empty\n");
		return start;
	}
	if(start->info==item){
	   tmp=(struct node *)malloc(sizeof(struct node));
	   tmp->info=data;
	   tmp->prev=NULL;
	   tmp->next=start;
       start->prev=tmp;
       start=tmp;
	   return start;	
	}
	p=start;
	while(p!=NULL){
		if(p->info==item){
	 	 tmp=(struct node *)malloc(sizeof(struct node));
	     tmp->info=data;
	     tmp->prev=p->prev;
	     tmp->next=p;
	     p->prev->next=tmp;
	     p->prev=tmp;
	     return start;
	    }
	    p=p->next;
	}
	printf("Item %d not found in list\n",item);
	return start;
}
struct node *addafter(struct node *start,int data,int item){
	struct node *tmp,*p;
	p=start;
	while(p!=NULL){
		if(p->info==item){
	 	 tmp=(struct node *)malloc(sizeof(struct node));
	     tmp->info=data;
	     tmp->prev=p;
	     tmp->next=p->next;
	     if(p->next!=NULL)
	       p->next->prev=tmp;
	     p->next=tmp;
	     return start;
	    }
	    p=p->next;
	}
	printf("Item %d not found in list\n",item);
	return start;
}
struct node *del(struct node *start,int data){
	struct node *tmp;
	if(start==NULL){
		printf("List is empty\n");
		return start;
	}
	if(start->next==NULL){
		if(start->info==data){
			tmp=start;
			start=NULL;
			free(tmp);
			return(start);
		}
		else{
			printf("element %d not found\n",data);
			return start;
		}
	}
	if(start->info==data){
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return(start);
	}
	tmp=start->next;
	while(tmp->next!=NULL){
		if(tmp->info==data){
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->next;
	}
	if(tmp->info==data){
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("Element %d not found\n",data);
	return start;
}





