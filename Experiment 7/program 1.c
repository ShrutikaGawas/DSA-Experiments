#include<stdio.h>
#include<stdlib.h>
struct node{
 struct node *lchild;
 int info;
 struct node *rchild;	
};

struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *ptr,int ikey);
struct node *del(struct node *ptr,int dkey);
int height(struct node *ptr);
void levelorder(struct node *ptr);
void displaygivenlevel(struct node *ptr,int level);

int main(){
	struct node *root=NULL, *ptr;
	int choice,data;
	while(1){
		printf("\n1.Search.\n");
		printf("2.Insert.\n");
		printf("3.Delete.\n");
		printf("4.Display.\n");
		printf("5.Exit.\n");
		printf("\nEnter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				   printf("\nEnter element to be searched: \n");
				   scanf("%d",&data);
				   ptr=search(root,data);
				   if(ptr==NULL)
				     printf("\nKey not present.");
				   else
				     printf("\nKey is present.");
				   break;
			case 2:
				   printf("\nEnter element to be inserted: ");
				   scanf("%d",&data);
				   root=insert(root,data);
				   break;
		    case 3:
		    	   printf("\nEnter element to be deleted: ");
		    	   scanf("%d",&data);
		    	   root=del(root,data);
		    	   break;
		    case 4:
		    	   printf("\nThe Tree elements are displayed in Levelorder Traversal: \n");
		    	   levelorder(root);
		    	   break;
		    	   
		    case 5:
		    	   exit(1);
		    default:
		    	    printf("\nINVALID INPUT");
		}
	}	
}

struct node *search(struct node *ptr, int skey){                     //search function
	if(ptr==NULL){
		printf("\nKey not found\n");
		return NULL;
	}
	else if(skey<ptr->info)
	  return search(ptr->lchild,skey);
	else if(skey>ptr->info)
	  return search(ptr->rchild,skey);
	else
	  return ptr;
}

struct node *insert(struct node *ptr,int ikey){                       //insert function
	if(ptr==NULL){                                                             //if root is empty
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

struct node *del(struct node *ptr,int dkey){                     //del function
	struct node *tmp,*succ;
	if(ptr==NULL){
		printf("%d not present in Tree\n",dkey);
		return ptr;
	}
	if(dkey < ptr->info)
	    ptr->lchild=del(ptr->lchild,dkey);
           else if(dkey > ptr->info)
                 ptr->rchild=del(ptr->rchild,dkey);
           else{
    	
    	    if(ptr->lchild!=NULL && ptr->rchild!=NULL){
    		succ=ptr->rchild;
    		while(succ->lchild!=NULL)
    		   succ=succ->lchild;
    		ptr->info=succ->info;
    		ptr->rchild=del(ptr->rchild,succ->info);
    	    }
    	  else{
    		  tmp=ptr;
    		  if(ptr->lchild!=NULL)
    		    ptr=ptr->lchild;
    		  else if(ptr->rchild!=NULL)
    		     ptr=ptr->rchild;
    		  else
    		    ptr=NULL;
    		free(tmp);
    	}
    }
    return ptr;
}

int height(struct node *ptr){                                    //height function
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

void levelorder(struct node *ptr){
	int h=height(ptr);
	int i;
	for(i=1;i<=h;i++)
	  displaygivenlevel(ptr,i);
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

