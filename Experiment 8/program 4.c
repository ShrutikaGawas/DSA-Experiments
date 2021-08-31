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

struct node *del(struct node *pptr,int dkey);
struct node *del_leftbalance(struct node *pptr,int *pshorter);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_rightbalance(struct node *pptr,int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);


int main(){
	int choice ,key,i=0;
	struct node *root=NULL;
	while(1){
		printf("\n\n1.Insertion.\n");
		printf("2.Delete.\n");
		printf("3.Inorder traversal.\n");
		printf("4.Exit.\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   printf("\nInsert keys for deletion to be performed: ");
				   for(i=0;i<10;i++){
				   	scanf("%d",&key);
				    root=insert(root,key);
				   }
				   break;
			case 2:
				   printf("\nEnter the key to be deleted: ");
				   scanf("%d",&key);
				   root=del(root,key);
				   break;
		   case 3:
		   	      printf("\nThe Inorder Traversal is: ");
		   	      inorder(root);
		          break;
		   case 4:
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
	aptr=pptr->lchild;
	pptr->lchild=aptr->rchild;
	aptr->rchild=pptr;
	return aptr;
}

struct node *Rotateleft(struct node *pptr){
	struct node *aptr;
	aptr=pptr->rchild;
	pptr->rchild=aptr->lchild;
	aptr->lchild=pptr;
	return aptr;
}
struct node *insert(struct node *pptr,int ikey){
	static int taller;
	if(pptr==NULL){
		pptr=(struct node *)malloc(sizeof(struct node));
		pptr->info=ikey;
		pptr->lchild=NULL;
		pptr->rchild=NULL;
		pptr->balance=0;
		taller= TRUE;
	}
	else if(ikey < pptr->info){
		pptr->lchild=insert(pptr->lchild,ikey);
		if(taller==TRUE)
		 pptr=insert_left_check(pptr,&taller);
	}
	else if(ikey > pptr->info){
		pptr->rchild=insert(pptr->rchild,ikey);
		if(taller==TRUE)
		 pptr= insert_right_check(pptr,&taller);
	}
	else{
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


struct node *del(struct node *pptr,int dkey){
	static int shorter;
	struct node *tmp,*succ;
	if(pptr==NULL){                                            //Base Case
		printf("Duplicate key\n");
		shorter=FALSE;
		return pptr;
	}
	else if(dkey < pptr->info){
		pptr->lchild=del(pptr->lchild,dkey);
		if(shorter==TRUE)
		 pptr=del_left_check(pptr,&shorter);
	}
	else if(dkey > pptr->info){
		pptr->rchild=del(pptr->rchild,dkey);
		if(shorter==TRUE)
		 pptr= del_right_check(pptr,&shorter);
	}
	else{                                                                                                   //dkey==pptr->info
		  if(pptr->lchild!=NULL && pptr->rchild!=NULL){           //pptr has 2 children
		  	succ=pptr->rchild;
		  	while(succ->lchild!=NULL)
		  	   succ=succ->lchild;
		  	pptr->info=succ->info;
		           pptr->rchild=del(pptr->rchild,succ->info);
		           if(shorter==TRUE)
		              pptr= del_right_check(pptr,&shorter);
		  }
		  else{
		  	tmp=pptr;
		  	if(pptr->lchild!=NULL)                       //only left child
		  	  pptr=pptr->lchild;
		  	else if(pptr->rchild !=NULL)            //only right child
		  	  pptr=pptr->rchild;
		  	else
		  	  pptr=NULL;                                     //no children
		  	free(tmp);
		  	shorter=TRUE;
		  }
	}
	return pptr;	
}

//Deletion from Left subtree
struct node *del_left_check(struct node *pptr, int *pshorter){
             printf("Deletion from left subtree\n");
	switch(pptr->balance){
		case 0:                                                                     //Case L_A: was balanced      
			pptr->balance=-1;                                    //now right heavy
			*pshorter=FALSE;
			break;
	           case 1:                                                                 //Case L_B: was left heavy
	    	          pptr->balance=0;                                       //now balanced
	    	          break;
	           case -1:                                                                       //Case L_C: was right heavy
	    	           pptr=del_rightbalance(pptr,pshorter);	                 //right balancing
    }
    return pptr;
}
struct node *del_rightbalance(struct node *pptr,int *pshorter){
	struct node *aptr,*bptr;
	aptr=pptr->rchild;
	if(aptr->balance==0){                                //Case L_C1
		pptr->balance=-1;
		aptr->balance=1;
		*pshorter=FALSE;
		pptr=Rotateleft(pptr);
		printf("Left Rotation Performed.\n");
	}
	else if (aptr->balance==-1){                     //Case L_C2
		 pptr->balance=0;
		 aptr->balance=0;
		 pptr=Rotateleft(pptr);	
    }
     else{                                                                       //Case L_C3
		bptr=aptr->lchild;
		switch(bptr->balance){
			case 0:                                                     //Case L_C3a
				   pptr->balance=0;
				   aptr->balance=0;
				   break;
			case 1:                                                      //Case L_C3b
				  pptr->balance=0;
				  aptr->balance=-1;
				  break;
		    case -1:                                                            //Case L_C3c
		    	   	pptr->balance=1;
	      	        aptr->balance=0;
				   
		}
		bptr->balance=0;
		pptr->rchild=Rotateright(aptr);
		pptr=Rotateleft(pptr);
		printf("Right-Left Rotation Performed.\n");
	}
	return pptr;
}
//Deletion from Right subtree
struct node *del_right_check(struct node *pptr, int *pshorter){
           printf("Deletion from right subtree\n");
	switch(pptr->balance){
		case 0:                                                  //Case R_A: was balanced
			pptr->balance=1;                   //now left heavy
			*pshorter=FALSE;
			break;
	    case -1:                                                     //Case R_B: was right heavy   
	    	 pptr->balance=0;                          //now balanced
	    	 break;
	    case 1:                                                   //Case R_C: was left heavy
	    	 pptr=del_leftbalance(pptr,pshorter);               //Left balancing
    }
    return pptr;
}

struct node *del_leftbalance(struct node *pptr,int *pshorter){
	struct node *aptr,*bptr;
	aptr=pptr->lchild;
	if(aptr->balance==0){                       //Case R_C1
		pptr->balance=1;
		aptr->balance=-1;
		*pshorter=FALSE;
		pptr=Rotateright(pptr);
		printf("Right Rotation Performed.\n");
	}
	else if (aptr->balance==1){                           //Case R_C2
		 pptr->balance=0; 
		 aptr->balance=0;
		 pptr=Rotateright(pptr);	
            }
            else{                                                                //Case R_C3
		bptr=aptr->rchild;
		switch(bptr->balance){
			case 0:                                         //Case R_C3a
				   pptr->balance=0;
				   aptr->balance=0;
				   break;
			case 1:                                     //Case R_C3b
				  pptr->balance=-1;
				  aptr->balance=0;
				  break;
		    case -1:                                          //Case R_C3c
		    	   	pptr->balance=0;
	      	        aptr->balance=1;
				   
	   }
		bptr->balance=0;
		pptr->rchild=Rotateleft(aptr);
		pptr=Rotateright(pptr);
		printf("Left-Right Rotation Performed.\n");
	}
	return pptr;
}
