#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
	int balance;
};

void inorder(struct node *ptr);
struct node *Rotateright(struct node *pptr);
struct node *Rotateleft(struct node *pptr);
struct node *insert(struct node *pptr,int ikey);
struct node *insert_leftbalance(struct node *pptr);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_rightbalance(struct node *pptr);
struct node *insert_right_check(struct node *pptr, int *ptaller);

int main(){
	int choice ,key;
	struct node *root=NULL;
	while(1){
		printf("\n\n1.Insert.\n");
		printf("2.Inorder traversal.\n");
		printf("3.Exit.\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   printf("\nEnter the key to be inserted: ");
				   scanf("%d",&key);
				   root=insert(root,key);
				   break;
		   case 2:
		   	      printf("\nThe Inorder Traversal is: ");
		   	      inorder(root);
		          break;
		   case 3:
		   	      exit(1);
		   default:
		   	       printf("\nINVALID INPUT");
		}
	}
}

void inorder(struct node *ptr){
	if(ptr==NULL)
	  return;
	inorder(ptr->lchild);
	printf("%d ",ptr->info);
	inorder(ptr->rchild);
}
struct node *Rotateright(struct node *pptr){
	struct node *aptr;
	aptr=pptr->lchild;                           //A is lchild of P
	pptr->lchild=aptr->rchild;             //rchild of A becomes lchild of P
	aptr->rchild=pptr;                          //P becomes rchild of A
	return aptr;                            //A is new root of subtree rooted at P
}

struct node *Rotateleft(struct node *pptr){
	struct node *aptr;
	aptr=pptr->rchild;                            //A is rchild of P
	pptr->rchild=aptr->lchild;              //lchild of A becomes rchild of P
	aptr->lchild=pptr;                           //P becomes lchild of A
	return aptr;                       //A is new root of subtree rooted at P
}


struct node *insert(struct node *pptr,int ikey){
	static int taller;
	if(pptr==NULL){                                                                             //Base case
		pptr=(struct node *)malloc(sizeof(struct node));
		pptr->info=ikey;
		pptr->lchild=NULL;
		pptr->rchild=NULL;
		pptr->balance=0;
		taller= TRUE;
	}
	else if(ikey < pptr->info){                                          //Insertion in left-subtree
		pptr->lchild=insert(pptr->lchild,ikey);
		if(taller==TRUE)
		 pptr=insert_left_check(pptr,&taller);
	}
	else if(ikey > pptr->info){                                         //Insertion in right-subtree
		pptr->rchild=insert(pptr->rchild,ikey);
		if(taller==TRUE)
		 pptr= insert_right_check(pptr,&taller);
	}
	else{                                                                                   //Base Case
		printf("Duplicate Key\n");
		taller=FALSE;
	}
	return pptr;
}
struct node *insert_left_check(struct node *pptr, int *ptaller){
	switch(pptr->balance){
		case 0:                                                          //Case_L_A: was balanced
			pptr->balance=1;                          //now left heavy
			break;
	    case -1:                                                           //Case_L_B: was right heavy 
	    	 pptr->balance=0;                                 //now balanced
	    	 *ptaller=FALSE;
	    	 break;
	    case 1:
	    	 pptr=insert_leftbalance(pptr);          //Case_L_C: was left heavy
	    	 *ptaller=FALSE;                                   //left balancing	 
    }
    return pptr;
}

struct node *insert_leftbalance(struct node *pptr){
	struct node *aptr,*bptr;
	aptr=pptr->lchild;
	if(aptr->balance==1){                         //Case L_C1: Insertion in AL
		pptr->balance=0;
		aptr->balance=0;
		pptr=Rotateright(pptr);
		printf("Right Rotation Performed.");
	}
	else{                                                                 //Case  L_C2: Insertion in AR
		bptr=aptr->rchild;
		switch(bptr->balance){
			case -1:                                    //Case L_C2a: Insertion in BR
				   pptr->balance=0;
				   aptr->balance=1;
				   break;
			case 1:                                   //Case L_C2b: Insertion in BL
				  pptr->balance=-1;
				  aptr->balance=0;
				  break;
		    case 0:                                        //Case L_C2c: B is newly inserted node 
		    	   	pptr->balance=0;
	      	        aptr->balance=0;
				   
		}
		bptr->balance=0;
		pptr->lchild=Rotateleft(aptr);
		pptr=Rotateright(pptr);
        printf("Left-Right Rotation Performed.");
	}
	return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller){
	switch(pptr->balance){
	    case 0:                                                             //Case_R_A: was balanced
			pptr->balance=-1;                      //now right heavy
			break;
	    case 1:                                                            //Case_R_B: was left heavy
	    	 pptr->balance=0;                                //now balanced
	    	 *ptaller=FALSE;
	    	 break;          
	    case -1:                                                         //Case_R_C: was right heavy
	    	 pptr=insert_rightbalance(pptr);      //right balancing
	    	 *ptaller=FALSE; 	 
    }
    return pptr;
}

struct node *insert_rightbalance(struct node *pptr){
	struct node *aptr,*bptr;
	aptr=pptr->rchild;
	if(aptr->balance==-1){                                      //Case R_C1: Insertion in AR
		pptr->balance=0;
		aptr->balance=0;
		pptr=Rotateleft(pptr);
		printf("Left Rotation Performed.");
	}
	else{                                                                //Case  R_C2: Insertion in AL
		bptr=aptr->rchild;
		switch(bptr->balance){
			case -1:                                     //Case R_C2a: Insertion in BR
				   pptr->balance=1;
				   aptr->balance=0;
				   break;
			case 1:                                   //Case R_C2b: Insertion in BL
				  pptr->balance=0;
				  aptr->balance=-1;
				  break;
		    case 0:                                        //Case R_C2c: B is newly inserted node
		    	   	pptr->balance=0;
	      	        aptr->balance=0;
				   
		}
		bptr->balance=0;
		pptr->rchild=Rotateright(aptr);
		pptr=Rotateleft(pptr);
		printf("Right-Left Rotation Performed.");
	}
	return pptr;
}
