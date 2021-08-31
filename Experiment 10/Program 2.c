#include<stdio.h>
#define MAX 10
enum typeofrecord{EMPTY,DELETED,OCCUPIED};
struct employee{
	int empid;
	char name[10];
	int age;
};
struct Record{
	struct employee info;
	enum typeofrecord status;
};

void insert(struct employee emprec, struct Record table[]);
void del(int key,struct Record table[]);
void display(struct Record table[]);
int search(int key,struct Record table[]);
int hash(int key);

main(){
	int i,key,choice;
	struct Record table[MAX];     //hash table
    struct employee emprec;
    for(i=0;i<=MAX-1;i++)
      table[i].status=EMPTY;
      while(1){
      	printf("\n\n1.Insert a Record.");
      	printf("\n2.Search a Record.");
      	printf("\n3.Delete a Record.");
    	printf("\n4.Display a Record.");
    	printf("\n5.Exit.");
    	printf("\nEnter your choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1:
    			  printf("\nEnter Empid,name and age: ");
    		 	  scanf("%d%s%d",&emprec.empid,&emprec.name,&emprec.age);
    		 	  insert(emprec,table);
    		      break;
    	    case 2:
    	    	    printf("\nEnter a key to be searched: ");
    	    	    scanf("%d",&key);
    	    	    i=search(key,table);
    	    	    if(i==-1)
    	    	     printf("Key not found.\n");
    	    	    else
    	    	     printf("Key is found at %d position.\n",i);
    	    	    break;
    	    case 3:
    	    	  printf("\nEnter a key to be deleted: ");
    	    	  scanf("%d",&key); 
    	    	  del(key,table);
    	    	  break;
    	    case 4:
    	    	   display(table);
    	    	   break;
    	    case 5:
    	    	   exit(1);
    	    	   break;
    	    default:
    	    	    printf("INVALID INPUT.\n");
    	}
      }
}
int search(int key,struct Record table[]){
	int h,i,loc;
	h=hash(key);
	loc=h;                   //location found by hashing
	for(i=1;i!=MAX-1;i++){
		if(table[loc].status==EMPTY)           //if loc is empty
		  return -1;
	    if(table[loc].info.empid==key)        
	      return loc;
	    loc=(h+i)%MAX;        //linear probing
	}
	return -1;
}
int hash(int key){                         //hash key
	return (key%MAX);                        
}
void insert(struct employee emprec, struct Record table[]){
	int h,i,loc;
	int key=emprec.empid;               //extract key from the record
	h=hash(key);                     //get location 
	loc=h;                        
	for(i=1;i!=MAX;i++){
		if(table[loc].status==EMPTY || table[loc].status==DELETED){  //if loc empty or deleted
			table[loc].info=emprec;   
			table[loc].status=OCCUPIED;
			printf("Record inserted\n");
			return;
		}
		if(table[loc].info.empid==key){
			printf("Duplicate key\n");
			return;
		}
		loc=(h+i)%MAX;   //linear probing method
	}
	printf("Table Overflow\n\n");
}
void del(int key,struct Record table[]){
	int loc=search(key,table);        //search location of key to be deleted
	if(loc==-1)
	  printf("Key not found.\n");
	else
	  table[loc].status=DELETED;        
}
void display(struct Record table[]){
	int i;
	for(i=0;i<MAX;i++){
		printf("[%d]:",i);
		if(table[i].status==OCCUPIED){
			printf("Occupied: %d %s",table[i].info.empid,table[i].info.name);
			printf("\t%d \n",table[i].info.age);
		}
		else if(table[i].status==DELETED)
		 printf("Deleted\n");
		else
		  printf("Empty\n\n");
	}
}
