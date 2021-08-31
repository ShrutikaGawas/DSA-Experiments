#include<stdio.h>
#include<stdlib.h>
typedef enum{false,true}boolean;
struct node{
 struct node *left;
 boolean lthread;
 int info;
 boolean rthread;
 struct node *right;	
};

void inorder(struct node *root);
void preorder(struct node *root);
struct node *in_succ(struct node *ptr);
struct node *in_pred(struct node *ptr);
struct node *insert(struct node *root,int ikey);

int main(){
	struct node *root = NULL;
	int i=0;
	int choice,data;
	while(1){
		printf("\n\n1.Insert 10 elements in the Tree.\n");
		printf("2.Display tree in In Order Traversal.\n");
		printf("3.Display tree in Pre-Order Traversal.\n");
		printf("4.Exit.\n");
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
				   printf("\nThe Inorder Traversal is: ");
				   inorder(root);
		    	   break;
				   
		    case 3:
		    	   printf("\nThe Preorder Traversal is: ");
				   preorder(root);
		    	   break;
		       
		    case 4:
		    	   exit(1);
		    default:
		    	    printf("\nINVALID INPUT");
		}
	}	
}

struct node *in_succ(struct node *ptr){
	if(ptr->rthread==true)
	   return ptr->right;
	else{
		ptr=ptr->right;
	    while(ptr->lthread==false)
	       ptr=ptr->left;
	    return ptr;
	}
}

struct node *in_pred(struct node *ptr){
  if(ptr->lthread==true)
	   return ptr->left;
	else{
		ptr=ptr->left;
	    while(ptr->rthread==false)
	       ptr=ptr->right;
	    return ptr;
	}
}

struct node *insert(struct node *root,int ikey){
	struct node *tmp,*par,*ptr;
	int found=0;
	ptr=root;
	par=NULL;
	while(ptr!=NULL){
		if(ikey==ptr->info){
			found=1;
			break;
		}
	
	   par=ptr;
	   if(ikey < ptr->info){
		 if(ptr->lthread==false)
		  ptr=ptr->left;
		else
		  break;
	   }
	   else{
		  if(ptr->rthread==false)
		  ptr=ptr->right;
		  else
		  break;
	   }
   }
   if(found)
    printf("Duplicate Key");
   else{
   	 tmp=(struct node *)malloc(sizeof(struct node));
   	 tmp->info=ikey;
   	 tmp->lthread=true;
   	 tmp->rthread=true;
   	  if(par==NULL){
   		   root=tmp;
   	 	  tmp->left=NULL;
   		  tmp->right=NULL;
   	   }
   
      else if(ikey<par->info){
   	    tmp->left=par->left;
   	    tmp->right=par;
   	    par->lthread=false;
   	    par->left=tmp;
      }
      else{
   	     tmp->right=par->right;
   	     tmp->left=par;
   	     par->rthread=false;
   	     par->right=tmp;
      }
   }
return root;
}
void inorder(struct node *root){
	struct node *ptr;
	if(root==NULL){
		printf("Tree is empty");
		return;
	}
	ptr=root;
	while(ptr->lthread==false)       //find the leftmost node
	 ptr=ptr->left;
	while(ptr!=NULL){
		 printf("%d ",ptr->info);
	 ptr=in_succ(ptr);                                   //find in_succ of each node
	}	 
}

void preorder(struct node *root){
	struct node *ptr;
	if(root==NULL){
	  printf("Tree is empty");
	  return;	
	}
	ptr=root;
	while(ptr!=NULL){
		printf("%d ",ptr->info);
		if(ptr->lthread==false)
		   ptr=ptr->left;
		else if(ptr->rthread==false)
		   ptr=ptr->right;
		else{
			while(ptr!=NULL && ptr->rthread==true)
			  ptr=ptr->right;
			if(ptr!=NULL)
			  ptr=ptr->right;
		}
	}
}
