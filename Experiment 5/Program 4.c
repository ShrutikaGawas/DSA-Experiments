//Implement Circular Queues using linked lists
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
void insert(int item);
int peek();
int del();
int isEmpty();
void display();
int main(){
	int choice,item;
	while(1){
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the elements at the front\n");
		printf("4.Display all the elements in the Queue\n");
		printf("5.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			       printf("Input the element to be added in the Queue: ");
				   scanf("%d",&item);
				   insert(item);
				   break;
			case 2:
				  item=del();
			      printf("Deleted item is: %d\n",item);
			      break;
		    case 3:
		    	  printf("Item at the front of the Queue is: %d\n",peek());
			      break;
		    case 4:
		    	   display();
		        	break;
		    case 5: exit(1);
		            break;
		    default:
		    	    printf("WRONG CHOICE\n");
		    	    
		    
		}
	}
	return 0;
}
void insert(int item){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
    	printf("Memory not available\n");
    	return;
    }
    tmp->info=item;
    tmp->link=NULL;
    if(front==NULL)
      front=tmp;
    else
      rear->link=tmp;
    rear=tmp;
}

int del(){
	struct node *tmp;
	tmp=front;
	if((front==NULL)&&(rear==NULL))
	 printf("\nQueue is Empty\n");
	else if(front==rear){
		front=rear=NULL;
		free(tmp);
	}
	else{
		front=front->link;
		rear->link=front;
		free(tmp);
	}
}

int isEmpty(){                                             
	if(front==NULL)
	  return 1;
	else
	  return 0;
}

int peek(){
	struct node *ptr;
	ptr=front;
	if(isEmpty()){
		printf("Queue Underflow\n");
    	return;
	}
	return ptr->info;
}

void display(){
	struct node *ptr;
	ptr=front;
	int i;
		if(isEmpty()){
		printf("Queue Underflow\n");
    	return;
	}
	printf("Queue is:\n");
    while(ptr!=NULL){
    	printf("%d\n",ptr->info);
    	ptr=ptr->link;
    }
	printf("\n");
}
