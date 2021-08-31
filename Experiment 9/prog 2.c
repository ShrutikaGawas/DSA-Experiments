#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;                        //number of vertices
int stack[MAX];   //can be initial,waiting or visited
int top=-1;
int adj[MAX][MAX];   //adjacency matrix
int state[MAX];
void creategraph();
void BFS(int v);
void BFStraversal();
int queue[MAX],front=-1,rear=-1;
void insertqueue(int vertex);
int deletequeue();
int isemptyqueue();
void push(int v);
int pop();
int isemptystack();
void DFStraversal();
void DFS(int v);

int main(){
	creategraph();
	BFStraversal();
	DFStraversal();
	
}

void creategraph(){
 	int maxedge,i,org,dest;
 	printf("Enter number of vertices: ");
	scanf("%d",&n);
	maxedge=n*(n-1);                       //max-edge in directed graph
	for(i=1;i<=maxedge;i++){
		printf("Enter edge %d(-1 -1 to quit): ",i);
		scanf("%d%d",&org,&dest);
		if((org==-1)&&(dest==-1))         
		  break;
	    if(org>=n||dest>=n||org<0||dest<0){
	    	printf("Invalid vertex\n");
	    	i--;
	    }
	    else
	     adj[org][dest]=1;                  //vertex inserted
	}
 }

int isemptyqueue(){
	if(front==-1||front>rear)
	  return 1;
	else  
	  return 0;
}

void insertqueue(int vertex){
	if(rear==MAX-1)
	 printf("Queue Overflow\n");
	else{
	 if(front==-1)      //if queue is initially empty
	   front=0;
	 rear=rear+1;
	 queue[rear]=vertex;
	}	 
}

int deletequeue(){
	int delitem;
	if(front==-1||front>rear){
		printf("Queue Overflow\n");
		exit(1);
	}
	delitem=queue[front];
	front=front+1;
	return delitem;
}

void BFStraversal(){
	int v;
	for(v=0;v<n;v++)
	  state[v]=initial;
    printf("Enter starting vertex for BFS:  \n");
    scanf("%d",&v);
    BFS(v);                     //BFS traversal
    for(v=0;v<n;v++)
	  if(state[v]==initial)   //if initial state
	    BFS(v);                //BFS traversal
}

void BFS(int v){
	int i;
	insertqueue(v);            //insert in queue
	state[v]=waiting;         // waiting state
	while(!isemptyqueue()){         //if queue not empty    
		v=deletequeue();            //delete from queue
		printf("%d ",v);       
		state[v]=visited;      //make state visited
		for(i=0;i<n;i++){
			//check for adjacent unvisited vertices 
			if(adj[v][i]==1 && state[i]==initial){
				insertqueue(i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}

void push(int v){
	if(top==MAX-1)
	 printf("Stack Overflow\n");
	else{
		top=top+1;
		stack[top]=v;
	}
}

int pop(){
	int v;
	if(top==-1){
	printf("Stack Underflow\n");
		exit(1);
	}
	v=stack[top];
	top=top-1;
	return v;
}

int isemptystack(){
	if(top==-1)
	  return 1;
	else  
	  return 0;
}

void DFStraversal(){
    int v;
    for(v=0;v<n;v++)
      state[v]=initial;           //state is initial in beginning
    printf("Enter starting vertex for DFS:  \n");
    scanf("%d",&v);
    DFS(v);       //DFS function
    for(v=0;v<n;v++)
	  if(state[v]=initial)
	    DFS(v);         
}

void DFS(int v){
	int i;
	push(v);      //push element on stack
	while(!isemptystack()){             //while stack isnt empty
		v=pop();                      //pop element from stack
		if(state[v]==initial){          //if in initial state
	   	  printf("%d ",v);               //print and make it as visited state
		  state[v]=visited;	
		}
		for(i=n-1;i>=0;i--){  
		      //check for adjacent unvisited vertices            
			if(adj[v][i]==1 && state[i]==initial){
				push(i);             //push it on stack
			}
		}
	}
	printf("\n");
}
