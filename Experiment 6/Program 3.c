#include<stdio.h>
#include<stdlib.h>
struct node{
	float coef;
	int expo;
	struct node *link;
};
struct node *create_list(struct node *start);
struct node *insert_s(struct node *start,float co,int ex);
struct node *insert(struct node *start,float co,int ex);
void display(struct node *ptr);
void poly_add(struct node *start1,struct node *start2);
int main(){
	struct node *start1=NULL, *start2=NULL;
	printf("Enter polynomial 1:\n");
	start1=create_list(start1);                              //function to create a poly.
	printf("Enter polynomial 2:\n");
	start2=create_list(start2);	
	printf("Polynomial 1 is: ");
	display(start1);
	printf("Polynomial 2 is: ");
	display(start2);
	poly_add(start1,start2);                                      //function to add 2 poly.
}
struct node *create_list(struct node *start){           //function to create polynomial
	int i,n,co,ex;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the coefficient for the term %d :",i);
		scanf("%d",&co);
		printf("Enter the exponent for the term %d :",i);
		scanf("%d",&ex);
		start=insert_s(start,co,ex);                
	}
	return start;
}
struct node *insert_s(struct node *start,float co,int ex){     //fu to place the terms in an exp.

	struct node *ptr,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	if(start==NULL ||ex>start->expo){
		tmp->link=start;
		start=tmp;
	}
	else{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->expo>=ex)
		    ptr=ptr->link;
		tmp->link=ptr->link;
		ptr->link=tmp;
	}
	return start;
}
void display(struct node *ptr){
	if(ptr==NULL){
		printf("Zero polynomial is: ");
		return;
	}
	while(ptr!=NULL){
		printf("(%.1fx^%d)",ptr->coef,ptr->expo);
		ptr=ptr->link;
		if(ptr!=NULL)
		 printf("+");
		else
		 printf("\n");
		 
	}
}
 void poly_add(struct node *p1,struct node *p2){             //function to add 2 poly.
 	struct node *start3;
 	start3=NULL;
 	while(p1!=NULL && p2!=NULL){
 		if(p1->expo>p2->expo){
 			start3=insert(start3,p1->coef,p1->expo);
 			p1=p1->link;
 		}
 		else if(p2->expo>p1->expo){
 			start3=insert(start3,p2->coef,p2->expo);
 			p2=p2->link;
 		}
 		else if(p2->expo==p1->expo){
 			start3=insert(start3,p1->coef+p2->coef,p1->expo);
 			p1=p1->link;
 			p2=p2->link;
 		}
 	}
 	while(p1!=NULL){
 		start3=insert(start3,p1->coef,p1->expo);
 		p1=p1->link;
 	}
 	while(p2!=NULL){
 			start3=insert(start3,p2->coef,p2->expo);
 			p2=p2->link;
 	}
 	printf("Added Polynomial is : ");
 	display(start3);
 }
 struct node *insert(struct node *start,float co,int ex){        //function creates added poly.
 	struct node *ptr,*tmp;
           tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	if(start==NULL || ex>start->expo){
		tmp->link=start;
		start=tmp;
	}
 	else{
 		ptr=start;
 		while(ptr->link!=NULL)
 		  ptr=ptr->link;
 		tmp->link=ptr->link;
 		ptr->link=tmp;
 		}
 	
 	return start;
 }
