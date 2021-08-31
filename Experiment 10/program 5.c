#include<stdio.h>
#include<stdlib.h>
#define MAX 11
struct employee{
	int empid;
	char name[10];
	int age;
};
struct Record{
	struct employee info;
	struct Record *link;
};
void insert(struct employee emprec, struct Record *table[]);
void del(int key,struct Record *table[]);
void display(struct Record *table[]);
int search(int key,struct Record *table[]);
int hash(int key);

main(){
	int i,key,choice;
	struct Record *table[MAX];
    struct employee emprec;
    for(i=0;i<=MAX-1;i++)
      table[i]=NULL;
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
int search(int key,struct Record *table[]){
	int h;
	struct Record *ptr;
	h=hash(key);
	ptr=table[h];
	while(ptr!=NULL){
		if(ptr->info.empid==key)
		  return h;
	    ptr=ptr->link;
	}
	return -1;
}
int hash(int key){
	return (key%MAX);
}
void insert(struct employee emprec, struct Record *table[]){
	int h;
	struct Record *tmp;
	int key=emprec.empid;         //extract key from record
    if(search(key,table)!=-1){
    	printf("Duplicate Key\n");
    	return;
    }
    h=hash(key);
    //insert in the beginning of the list
    tmp=malloc(sizeof(struct Record));
    tmp->info=emprec;
    tmp->link=table[h];
    table[h]=tmp;
}
void del(int key,struct Record *table[]){
	int h;
	struct Record *tmp,*ptr;
	h=hash(key);
	if(table[h]==NULL){
		printf("Key  %d is not found\n",key);
		return;
	}
	if(table[h]->info.empid==key){
		tmp=table[h];
		table[h]=table[h]->link;
		free(tmp);
		return;
	}
	ptr=table[h];
	while(ptr->link!=NULL){
		if(ptr->link->info.empid==key){
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return;
		}
		ptr=ptr->link;
	}
	printf("Key %d not found\n",key);
}
void display(struct Record *table[]){
	int i;
	struct Record *ptr;
	for(i=0;i<MAX;i++){
		printf("\n[%d] ",i);
		if(table[i]!=NULL){
			ptr=table[i];
			while(ptr!=NULL){
				printf("%d %s %d\t",ptr->info.empid,ptr->info.name,ptr->info.age);
				ptr=ptr->link;
			}
			
		}
		printf("\n");
	}
}
