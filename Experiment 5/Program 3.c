#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue_arr[MAX];
int rear=-1,front=-1;
void insert(int item);
int del();
int peek();
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
			       printf("Enter the element for insertion: ");
				   scanf("%d",&item);
				   insert(item);
				   break;
			case 2:
			      item=del();
			      printf("Deleted element is: %d\n",item);
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
    if(isFull()){
    	printf("Queue Overflow\n");
    	return;
    }
    if(front==-1)
      front = 0;
    if(rear==MAX-1)
      rear=0;
    else
      rear=rear+1;
    queue_arr[rear]=item;
}

int del(){
	int item;
	if(isEmpty()){
		printf("Queue Underflow\n");
    	exit(1);
	}
	item=queue_arr[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
    else if(front==MAX-1)
	 front=0;
	else
	  front=front+1;
	return item;
}
int isEmpty(){
	if(front==-1)
	  return 1;
	else
	  return 0;
}
int isFull(){
	if((front==0 && rear==MAX-1)||(front==rear+1))
	 return 1;
	else
	 return 0;
}
int peek(){
	if(isEmpty()){
		printf("Queue Underflow\n");
    	return;
	}
	return queue_arr[front];
}
void display(){
	int i;
		if(isEmpty()){
		printf("Queue Underflow\n");
    	return;
	}
	i=front;
    if(front<=rear){
    	while(i<=rear)
    	  printf("%d\n",queue_arr[i++]);
    }
    else{
    	while(i<=MAX-1)
    	    printf("%d\n",queue_arr[i++]);
    	i=0;
    	while(i<=rear)
    	   printf("%d\n",queue_arr[i++]);
    }
    printf("\n");
}
