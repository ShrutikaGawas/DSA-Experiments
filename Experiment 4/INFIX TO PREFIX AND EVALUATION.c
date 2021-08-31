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
void infix_to_prefix();
long int eval_pre();
int instack_priority(char symbol);
int symbol_priority(char symbol);
int white_space(char symbol);
char infix[MAX],prefix[MAX];
long int stack[MAX];
int main(){
	long int value;
	printf("Enter infix: ");
	gets(infix);
	infix_to_prefix();
	printf("Prefix %s\n",prefix);
	value=eval_pre();
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
	if(top==-1){
		printf("Stack Underflow");
	    exit(1);
	}
	return stack[top--];
}
//infix to prefix function
void infix_to_prefix(){
	int i,j=0,p=0,temp=0;
	char next;
	char symbol;
	for(i=strlen(infix)-1;i>=0;i--){
		symbol=infix[i];
		if(!white_space(symbol)){
			switch(symbol){
				case ')':
					    push(symbol);
					    break;
				case '(':
					    while((next=pop())!=')')
					     prefix[p++]=next;
					     break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					    while( (top!=-1) && instack_priority( stack[top] ) > symbol_priority(symbol) )
					       prefix[p++]=pop();
					    push(symbol);
					    break;
				default:
					   prefix[p++]=symbol;
			}
		}
	}
	while(top!= -1)
	   prefix[p++]=pop();
	prefix[p]='\0';
	for(i=0,j=p-1;i<j;i++,j--){
		temp=prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=temp;
	}
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
			case ')':
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
int symbol_priority(char symbol){
	switch(symbol){
			case ')':
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
long int eval_pre(){
	long int a,b,temp,result;
	 int i;
	for(i=strlen(prefix)-1;i>=0;i--){
		if(prefix[i]<='9'&&prefix[i]>='0')
		  push(prefix[i]-'0');
		else{
			a=pop();
			b=pop();
			switch(prefix[i]){
				
			case '+':
			     	temp=a+b;
				    break;
			case '-': 
			        temp=a-b;
				    break;
			case '*':
				    temp=a*b;
				    break;
			case '/':
				    temp=a/b;
				    break;
			case '%':
				    temp=a%b;
				    break;
			case '^':
				    temp=pow(a,b);
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





