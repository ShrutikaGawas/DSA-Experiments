#include<stdio.h>
#include<stdlib.h>
struct node{
 struct node *lchild;
 int info;
 struct node *rchild;	
};

struct node *insert(struct node *ptr,int ikey);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
int height(struct node *ptr);
void levelorder(struct node *ptr);
void displaygivenlevel(struct node *ptr,int level);

int main(){
	struct node *root=NULL, *ptr;
	int i=0;
	int choice,data;
	while(1){
		printf("\n\n1.Insertion of 10 Elements.\n");
		printf("2.Pre-Order Traversal.\n");
		printf("3.In Order Traversal.\n");
		printf("4.Post Order Traversal.\n");
		printf("5.Level Order Traversal.\n");
		printf("6.Exit.\n");
		printf("\nEnter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   printf("\nInsert 10 Elements into the Tree: \n");
				   for(i=0;i<10;i++){
				   	scanf("%d",&data);
				    root=insert(root,data);
				   }
				   break;
			case 2:
				   printf("\nThe Pre Order Traversal is: ");
				   preorder(root);
				   break;
		    case 3:
		    	   printf("\nThe In Order Traversal is: ");
				   inorder(root);
		    	   break;
		    case 4:
		    	   printf("\nThe Post Order Traversal is: ");
				   postorder(root);
		    	   break;
		    case 5:
		    	   printf("\nThe Tree elements are displayed in Levelorder Traversal: \n");
		    	   levelorder(root);
		    	   break; 	   
		    case 6:
		    	   exit(1);
		    default:
		    	    printf("\nINVALID INPUT");
		}
	}	
}

struct node *insert(struct node *ptr,int ikey){                           //insert function
	if(ptr==NULL){
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->info=ikey;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
	}
	else if(ikey < ptr->info)
	  ptr->lchild=insert(ptr->lchild,ikey);
	else if(ikey > ptr->info)
	  ptr->rchild=insert(ptr->rchild,ikey);
	else
	 printf("Duplicate Key \n");
	return ptr;
}

void preorder(struct node *ptr){                                //pre-order function
	if(ptr==NULL)
	  return;
	printf("%d ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node *ptr){                                //in-order function
	if(ptr==NULL)
	  return;
	inorder(ptr->lchild);
	printf("%d ",ptr->info);
	inorder(ptr->rchild);
}

void postorder(struct node *ptr){                              //post order function
	if(ptr==NULL)
	  return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d ",ptr->info);
}

void levelorder(struct node *ptr){                          //level order function
	int h=height(ptr);
	int i;
	for(i=1;i<=h;i++)
	  displaygivenlevel(ptr,i);
}

int height(struct node *ptr){
	int hleft,hright;
	if(ptr==NULL)
	 return 0;
	hleft=height(ptr->lchild);
	hright=height(ptr->rchild);
	if(hleft>hright)
	  return 1+hleft;
	else
	  return 1+hright;
}
void displaygivenlevel(struct node *ptr,int level){
	if(ptr==NULL)
	    return;
	if(level==1)
	    printf("%d ",ptr->info);
	else if(level>1){
		displaygivenlevel(ptr->lchild,level-1);
		displaygivenlevel(ptr->rchild,level-1);
	}
}
