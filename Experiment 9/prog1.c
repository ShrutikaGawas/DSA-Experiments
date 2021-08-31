#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];                             //Adjacency Matrix                
int n;                                         //number of vertices in graph
void creategraph();
void display();
void insertedge(int org,int dest);
void deleteedge(int org,int dest);
void deletevertex(int u);
void insertvertex();

int main(){
	
    int choice,u,org,dest;
    creategraph();
	while(1){
		printf("\n1.Insert a Vertex.\n");
		printf("2.Insert an Edge.\n");
		printf("3.Delete a Vertex.\n");
		printf("4.Delete an Edge.\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("\nEnter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   insertvertex();
				   break;
			case 2:
				   printf("\nEnter an Edge to be inserted: ");
				   scanf("%d%d",&org,&dest);
				   insertedge(org,dest);
				   break;
		    case 3:
		    	   printf("\nEnter Vertex to be deleted: ");
		    	   scanf("%d",&u);
		    	   deletevertex(u);
		    	   break;
		    case 4:
		    	   printf("\nEnter an Edge to be deleted: ");
		    	   scanf("%d%d",&org,&dest);
		    	   deleteedge(org,dest);
		    	   break;
		    case 5:
		    	display();
		    	break;
		    case 6:
		    	   exit(1);
		    default:
		    	    printf("\nINVALID INPUT");
		}
	}	
}
 void creategraph(){
 	int maxedge,i,org,dest;
 	printf("Enter number of vertices: ");
	scanf("%d",&n);
	maxedge=n*(n-1);                              //condition for max-edge in directed graph
	for(i=1;i<=maxedge;i++){
		printf("Enter edge %d(-1 -1 to quit): ",i);
		scanf("%d%d",&org,&dest);
		if((org==-1)&&(dest==-1))          //to quit entering edges
		  break;
	    if(org>n||dest>n||org<0||dest<0){      //condition for invalid vertex
	    	printf("Invalid vertex\n");
	    	i--;
	    }
	    else
	     adj[org][dest]=1;     //insert an edge
	}
 }
 
void insertvertex(){
	int i;
	n++;                                      //increment n
	printf("The Inserted node is %d \n",n);
	for(i=0;i<n;i++){                         
		adj[i][n]=0;
		adj[n][i]=0;
	}
}

 void deletevertex(int u){
	int i,j;
	if(n==0){                           //check if graph is empty
		printf("Graph is empty\n");
		return;
	}
	if(u>n){                          //if vertex to be deleted > actual no.of vertices
		printf("This vertex isn't present in the graph\n");
		return;
	}
	for(i=u;i<=n-1;i++)          //to delete the desired vertex
	  for(j=1;j<=n;j++){
	  	adj[i][j]=adj[i+1][j];    //adjust edges of vertices after deleted vertex
	  }
	  n--;                    //decrement n
}
 
 void insertedge(int org,int dest){
 	if(org<0||org>n){
 		printf("Origin vertex doesn't exist\n");
 		return;
 	}
 	if(dest<0||dest>n){
 	    printf("Destination vertex doesn't exist\n");
 		return;
 	}
 	adj[org][dest]=1;           //insert edge
 }
 
 void deleteedge(int org,int dest){
 	if(org<0||org>n||dest>n||adj[org][dest]==0){
 		printf("This edge doesn't exist\n");
 		return;
 	}
 	adj[org][dest]=0;           //delete edge
 }
 
 void display(){
 	int i,j;
 	for(i=1;i<=n;i++){
 		for(j=1;j<=n;j++)
 	       printf("%d",adj[i][j]);
 	    printf("\n");
	 }
 }
