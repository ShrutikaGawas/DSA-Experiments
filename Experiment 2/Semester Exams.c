//Program to input details of student and display the class he attained in his Semester exams.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct semester
	{
		int marks[6];
	};
struct Student
{
	int roll;
	char name[20];
	int clas;
	int semester;
	struct semester sem;
};
int main()
{
	system("color 7");
	int i,n,j,k,total=0;
	struct Student *st;
	printf("Enter the number of Entries to be stored: ");
	scanf("%d",&n);
     st=(struct Student*)malloc(n*sizeof(struct Student));
	for(i=0;i<n;i++)
	{
		printf("\nEnter Student's Name: ");
		scanf("%s",&(st+i)->name);
		printf("Enter Student's Rollno: ");
		scanf("%d",&(st+i)->roll);
		printf("Enter Student's class(Year): ");
		scanf("%d",&(st+i)->clas);	
		printf("Enter Semester: ");
		scanf("%d",&(st+i)->semester);
		printf("Enter the marks scored in each subject(out of 100): ");
			for(k=0;k<6;k++)
			{
				scanf("%d",&(st+i)->sem.marks[k]);
			}
		printf("\n");
	}

	for(i=0;i<n;i++)
	{		
	    printf("\nStudent's Name: %s",(st+i)->name);
	    printf("\nStudent's Rollno:%d",(st+i)->roll);
	    printf("\nStudent's Class:%d",(st+i)->clas);
	    printf("\nStudent's Semester: %d",(st+i)->semester);
	    total=0;
		for(k=0;k<6;k++)
		{ 
		  	total+=(st+i)->sem.marks[k];
		}
		printf("\n Total marks are: %d\n",total);
		if(total>=500&&total<600)
		  printf("First Class Recieved");
		else if(total<500 &&total>=400) 
		  printf("Second Class Recieved");
		else if(total<400 &&total>=300) 
		  printf("Third Class Recieved");
		else if(total<300 &&total>=200) 
		  printf("Fourth  Class Recieved");
		else if(total<200) 
		  printf("Fifth Class Recieved");
		else
		 printf("Total exceeds 600!!! INVALID INPUT FOR MARKS");
	    printf("\n");
	}	
}
