#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct node{
	int info;
	struct node *link;
}*top=NULL;
char stack[MAX];
char pop();
void push(char);
int isEmpty();
main(){
	char str[50];
	unsigned int i;
	printf("Enter the string: ");
	gets(str);
	for(i=0;i<strlen(str);i++)
	  push(str[i]);
	for(i=0;i<strlen(str);i++)
	  str[i]=pop();
	printf("Reversed string is: ");
	puts(str);
}
void push(char item){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL){
		printf("Stack Overflow\n");
		return;
	}
	tmp->info=item;
	tmp->link=top;
	top=tmp;
}
char pop(){
	struct node *tmp;
	char item;
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}
int isEmpty(){
	if(top==NULL)
	 return 1;
	else
	  return 0;
}
