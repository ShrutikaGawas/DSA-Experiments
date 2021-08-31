#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 40
struct node{
	char info;
	struct node *link;
}*top=NULL;
int stack[MAX];
void push(char);
char pop();
int match(char a,char b);
main(){
	char exp[MAX];
	int valid;
	printf("Enter Algebraic Expression: ");
	gets(exp);
	valid=check(exp);                                 //check function checks the validity of expression
	if(valid==1)
	  printf("Valid Expression\n");
	else
	  printf("Invalid Expression\n");
}
int check(char exp[]){
	int i;
	char temp;
	for(i=0;i<strlen(exp);i++)              //scan expression from L to R
	{
		if(exp[i]=='(' ||exp[i]=='{'||exp[i]=='[')                     //if L paren. 
		       push(exp[i]);                                                           // push on stack
	    if(exp[i]==')' ||exp[i]=='}'||exp[i]==']')                      //if R paren.
	        if(top==NULL)                                                            //if stack empty
	        {
	        	printf("Right Parentheses are more than left");
	        	return 0;
	        }
	        else
	        {
	        	temp=pop();               //pop an element from stack
	        	if(!match(temp,exp[i]))                //if popped element doesn’t match 
	        	{
	        		printf("Mismatched parentheses are: ");
	        		printf("%c and %c\n",temp,exp[i]);
	        		return 0;
	        	}
	        }
	}
	if(top==NULL)                             //after scanning if stack is empty
	{
		printf("Balanced Parentheses\n");
		return 1;
	}
	Else                                                 //if stack isn’t empty
	{
	  printf("Left Parentheses are more than right parentheses\n");
	  return 0;
	}
}
int match(char a,char b){
	if(a=='['&& b==']')
	   return 1;
	if(a=='{'&& b=='}')
	   return 1;
	if(a=='(' && b==')')
	   return 1;
	return 0;
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
	int item;
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
