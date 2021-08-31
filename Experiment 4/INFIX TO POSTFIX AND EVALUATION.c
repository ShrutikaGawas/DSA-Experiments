#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push(long int symbol);
int top=-1;
long int pop();
void infix_to_postfix();
long int eval_post();
int instack_priority(char symbol);
int symbol_priority(char symbol);
int white_space(char );
char infix[MAX],postfix[MAX];
long int stack[MAX];
//main function
int main(){
	long int value;
	printf("Enter infix: ");
	gets(infix);
	infix_to_postfix();
	printf("Postfix %s\n",postfix);
	value=eval_post();
	printf("Value of the expression:%ld\n",value);
    return 0;
}
//push function
void push(long int symbol){
	if(top==MAX-1){
		printf("Stack Overflow\n");
		exit(1);
	}
	stack[++top]=symbol;
}
//pop function
long int pop(){
	if(isEmpty()){
		printf("Stack Underflow");
	    exit(1);
	}
	return stack[top--];
}
//infix to postfix
void infix_to_postfix(){
	int i,p=0;
	char next;
	char symbol;
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
		if(!white_space(symbol)){
			switch(symbol){
				case '(':
					    push(symbol);
					    break;
				case ')':
					    while((next=pop())!='(')
					     postfix[p++]=next;
					     break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					    while( (top!=-1) && instack_priority( stack[top] ) >=symbol_priority(symbol) )
					       postfix[p++]=pop();
					    push(symbol);
					    break;
				default:
					   postfix[p++]=symbol;
			}
		}
	}
	while(!isEmpty( ))
	   postfix[p++]=pop();
	 postfix[p]='\0';
}                
//whitespace function
int white_space(char symbol){
	if(symbol==BLANK||symbol==TAB)
	return 1;
	else
	return 0;
}
//stack priority
int instack_priority(char symbol){
	switch(symbol){
			case '(':
					   return 0;
			case '+':
			case '-':
				      return 1;
			case '*':
			case '/':
			case '%':
				     return 2;
			case '^':
				    return 3;
	}
}
//stack priority
int symbol_priority(char symbol){
	switch(symbol){
			case '(':
			         return 0;
			case '+':
			case '-':
				      return 1;
			case '*':
			case '/':
			case '%':
				     return 2;
			case '^':
				    return 4;
	}
}
//evaluation function
long int eval_post(){
	long int a,b,temp,result;
	int i;
	for(i=0;i<strlen(postfix);i++){
		if(postfix[i]<='9'&&postfix[i]>='0')
		  push(postfix[i]-'0');
		else{
			a=pop();
			b=pop();
			switch(postfix[i]){
				
			case '+':
			     	temp=b+a;
				    break;
			case '-': 
			        temp=b-a;
				    break;
			case '*':
				    temp=b*a;
				    break;
			case '/':
				    temp=b/a;
				    break;
			case '%':
				    temp=b%a;
				    break;
			case '^':
				    temp=pow(b,a);
				    break;
			}
			push(temp);
		}
	}
	result=pop();
	return result;
}
//isEmpty function
int isEmpty(){
	if(top==-1)
	  return 1;
	else
	  return 0;
}




