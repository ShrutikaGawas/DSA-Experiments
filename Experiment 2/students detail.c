//Program to accept student's details and print student's details with age greater than 20
#include<stdio.h>
#include<stdlib.h>
struct Student
{
	char name[15];
	int id;
	int age;
	char stream[30];
};
int main()
{
	system("color 7");
	struct Student *st;
	int i,n;
	printf("\nEnter the number of Entries to be stored: ");
	scanf("%d",&n);
	st=(struct Student*)malloc(n*sizeof(struct Student));
	if(st==NULL)
	{
		printf("Insufficient Memory.............\n ");
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter Student's ID: ");
		scanf("%d",&(st+i)->id);
		printf("Enter Student's Name: ");
		scanf("%s",&(st+i)->name);
		printf("Enter Age: ");
		scanf("%d",&(st+i)->age);
		printf("Enter Stream: ");
		scanf("%s",&(st+i)->stream);
		printf("\n");
	}
	printf("\n\n---------DETAILS----------\n\n");
	for(i=0;i<n;i++)
	{
		if((st+i)->age>20)
		{
			printf("\nStudent's ID: %d",(st+i)->age);
		    printf("\nStudent's Name: %s",(st+i)->name);
		    printf("\nStudent's Age: %d",(st+i)->age);
		    printf("\nStudent's Stream: %s",(st+i)->stream);
            printf("\n");
		}	
	}
}
