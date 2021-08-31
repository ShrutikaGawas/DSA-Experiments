//Program to create a Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create_list(struct node*start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main(){
	struct node *start=NULL;
	int choice,data,pos,item;
	while(1){
		printf("\n1.Create a List\n");
	    printf("2.Display List\n");
		printf("3.Count Elements \n");
		printf("4.Search\n");
		printf("5.Add to Empty/Add to Beginning\n");
	    printf("6.Add at the end\n");
		printf("7.Add after the node\n");
		printf("8.Add before the node\n");
		printf("9.Add at the position\n");
		printf("10.Delete Element\n");
		printf("11.Reverse the List\n");
		printf("12.Quit\n\n");
		
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
				count(start);
				break;
			case 4:
				printf("Enter the element to be searched:");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("Enter the elements to be inserted:");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			case 6:
				printf("Enter the elements to be inserted:");
				scanf("%d",&data);
				start=addatend(start,data);
				break;
			case 7:
				printf("Enter the elements to be inserted:");
				scanf("%d",&data);
				printf("Enter the element after which to insert:");
				scanf("%d",&item);
				start=addafter(start,data,item);
				break;
			case 8:
				printf("Enter the elements to be inserted:");
				scanf("%d",&data);
				printf("Enter the element before which to insert:");
				scanf("%d",&item);
				start=addbefore(start,data,item);
				break;
			case 9:
				printf("Enter the elements to be inserted:");
				scanf("%d",&data);
			    printf("Enter the position at which to insert:");
				scanf("%d",&pos);
				start=addatpos(start,data,pos);
				break;
			case 10:
				printf("Enter the element to be deleted:");
				scanf("%d",&data);
				start=del(start,data);
				break;
			case 11:
				start=reverse(start);
				break;
			case 12:
				exit(1);
			default:
				printf("YOU HAVE GIVEN A WRONG ENTRY!!");
		}
		
	}
	return 0;
}
//create list function
struct node *create_list(struct node*start){
	int i,n,data;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	return start;
	printf("enter the elements to be inserted:");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(i=2;i<=n;i++){
		printf("enter the elements to be inserted:");
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
	printf("\n\n");
}
//count function
void count(struct node *start){
		struct node *p;
		int cnt=0;
		p=start;
			while(p!=NULL){
			p=p->link;
	        cnt++;
			}
        printf("\nNumber of elements are: %d \n",cnt);	
}
//search function
void search(struct node *start,int data){
	struct node *p=start;
	int pos=1;
		while(p!=NULL){
		if(p->info==data){
			printf("\nItem %d is found at position %d\n",data,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("Item is not found!!!!");
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
//add after function
struct node *addafter(struct node *start,int data,int item)
{
	struct node *p,*tmp;
	p=start;
	while(p!=NULL){
		if(p->info==item){
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("\nitem %d not found in list!\n",item);
	return start;
}
//add before function
struct node *addbefore(struct node *start,int data,int item)
{
	struct node *p,*tmp;
	if(start==NULL){
		printf("List is empty");
		return start;
	}
	if(start->info==item){
		tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=start;
			start=tmp;
			return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==item){
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("item %d not found in list!\n",item);
	return start;
}
//add at position function
struct node *addatpos(struct node *start,int data,int pos){
	struct node *tmp,*p;
	int i;
	tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    if(pos==1){
    	tmp->link=start;
    	start=tmp;
    	return start;
    }
    p=start;
    for(i=1;i<pos-1&&p!=NULL;i++)
     p=p->link;
     if(p==NULL)
       printf("There are less than %d elements\n",pos);
    else{
    	tmp->link=p->link;
    	p->link=tmp;
    }
    return start;
}
//delete function
struct node *del(struct node *start,int data){
	struct node *tmp,*p;
	if(start==NULL){
		printf("List is empty!");
		return start;
	}
	if(start->info==data){
		tmp=start;
		start=start->link;
		free(tmp);
		return start;		
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==data){
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d mot found\n",data);
	return start;
}
//reverse function
struct node *reverse(struct node *start){
	struct node *ptr,*prev,*next;
	prev=NULL;
	ptr=start;
	while(ptr!=NULL){
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}
