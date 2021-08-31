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

struct node *in_succ(struct node *ptr);
struct node *in_pred(struct node *ptr);
struct node *insert(struct node *root,int ikey);
struct node *case_a(struct node *root,struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root,struct node *par,struct node *ptr);
struct node *del(struct node *root,int dkey);
void inorder(struct node *root);
void preorder(struct node *root);


void inorder(struct node *root){
	struct node *ptr;
	if(root==NULL){
		printf("Tree is empty");
		return;
	}
	ptr=root;
	while(ptr->lthread==false)
	 ptr=ptr->left;
	while(ptr!=NULL){
		 printf("%d ",ptr->info);
	 ptr=in_succ(ptr);
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


int main(){
	struct node *root = NULL;
	int i=0;
	int choice,data;
	while(1){
		printf("\n\n1.Insert.\n");
		printf("2.Delete.\n");
		printf("3.Display tree as Levelorder Traversal.\n");
		printf("4.Exit.\n");
		printf("\nEnter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   printf("\nInsert Element into the Tree: \n");
				   scanf("%d",&data);
				   root=insert(root,data);
				   break;
			case 2:
				   printf("\nEnter element to be deleted: ");
		    	   scanf("%d",&data);
		    	   root=del(root,data);
		    	   break;
				   
		    case 3:
		    	   printf("\nThe Levelorder Traversal is: ");
				   inorder(root);
		    	   break;
		       
		    case 4:
		    	   exit(1);
		    default:
		    	    printf("\nINVALID INPUT");
		}
	}	
}

struct node *in_succ(struct node *ptr){
	if(ptr->rthread==true)                                   //right ptr is thread (pts to in_succ)
	   return ptr->right;
	else{                                                               //if right ptr not  thread
		ptr=ptr->right;                                 //move to its right child
	    while(ptr->lthread==false)                  //keep moving L till we find no left child
	       ptr=ptr->left;
	    return ptr;                                            
	}
}

struct node *in_pred(struct node *ptr){
  if(ptr->lthread==true)                                  //left ptr is thread (pts to in_pred)
	   return ptr->left;
	else{                                                            //if left ptr not a thread
		ptr=ptr->left;                                 //move to left child
	    while(ptr->rthread==false)               //keep moving R till we find no right child
	       ptr=ptr->right;
	    return ptr;
	}
}

struct node *insert(struct node *root, int ikey){               //insert function           
	struct node *tmp,*par,*ptr;
	int found=0;
	ptr=root;
	par=NULL;
	while(ptr!=NULL){                             //if root is not null
		if(ikey==ptr->info){            //check if element to be inserted is present in tree 
			found=1;
			break;
		}
	
	   par=ptr;
	   if(ikey < ptr->info){                             
		if(ptr->lthread==false)                  
		     ptr=ptr->left;
		else                                                  //left-thread found then search terminates
		  break;
	   }
	   else{
		  if(ptr->rthread==false)
		     ptr=ptr->right;
		  else                                        //right-thread found then search terminates
		  break;
	   }
   }
   if(found)
     printf("\nDuplicate Key");
   else{
   	 tmp=(struct node *)malloc(sizeof(struct node));   //new node tmp insrtd as leaf node
   	 tmp->info=ikey;
   	 tmp->lthread=true;
   	 tmp->rthread=true;
   	  if(par==NULL){                              //insertion in empty tree
   		   root=tmp;
   	 	  tmp->left=NULL;
   		  tmp->right=NULL;
   	   }
   
      else if(ikey<par->info){                           //new node inserted as left child
   	    tmp->left=par->left;
   	    tmp->right=par;
   	    par->lthread=false;
   	    par->left=tmp;
      }
      else{                                                            //new node inserted as right child
   	     tmp->left=par;
   	     tmp->right=par->right;
   	     par->rthread=false;
   	     par->right=tmp;
      }
   }
return root;
}

struct node *del(struct node *root,int dkey){
	struct node *par,*ptr;
	int found=0;
	ptr=root;
	par=NULL;
	while(ptr!=NULL){                                //while loop to search the key to be deleted 
		if(dkey==ptr->info){
			found=1;
			break;
		}
		par=ptr;
		if(dkey < ptr->info){
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
	if(found==0)
	   printf("%d not present in the tree",dkey);
	else if(ptr->lthread==false && ptr->rthread==false)
	   root = case_c(root,par,ptr);         //node to be deleted has 2 children
	else if(ptr->lthread==false)
	   root = case_b(root,par,ptr);        //node to be deleted has 1 left child
	else if(ptr->rthread==false)
	   root = case_b(root,par,ptr);       //node to be deleted has 1 right child
	else 
	   root=case_a(root,par,ptr);         //node to be deleted has no children
	return root; 
}



struct node *case_a(struct node *root,struct node *par,struct node *ptr){
	if(ptr==NULL)                                        //dkey is in root node
	    root=NULL;
	else if(ptr==par->left){                      //if dkey is left child
		par->lthread=true;                //L ptr of parent is made a thread
		par->left=ptr->left;              //pointing to its pred.
	}
	else{                                         
		par->rthread=true;                   //R ptr of parent is made a thread
		par->right=ptr->right;              //pointing to its succ.
	}
	free(ptr);
	return root;
}

struct node *case_b(struct node *root,struct node *par,struct node *ptr){
	struct node *child,*p,*s;
	if(ptr->lthread==false)
	   child=ptr->left;
	else
	   child=ptr->right;
	if(par==NULL)
	   root=child;
	else if(ptr==par->left)
	   par->left=child;
	else
	   par->right=child;
	s=in_succ(ptr);                                 //in-order succ and pred of node are found
	p=in_pred(ptr);
	if(ptr->lthread==false)                         //if dkey has left subtree
	   p->right=s;                                          //rthread of pred  points to succ 
	else if(ptr->rthread==false)               //if dkey has right subtree
	   s->left=p;                                           //lthread of succ points to pred
	free(ptr);
	return root;
}

struct node *case_c(struct node *root,struct node *par,struct node *ptr){
	struct node *succ,*parsucc;
           //finding in-order succ and its parent
	parsucc=ptr;                                         
	succ=ptr->right;
	while(succ->left!=NULL){
		parsucc=succ;
		succ=succ->left;
	}
	ptr->info=succ->info;                              
	if(succ->lthread==true && succ->rthread==true)
	    root = case_a(root,parsucc,succ);
	else
	   root=case_b(root,parsucc,succ);
	return root;
}
