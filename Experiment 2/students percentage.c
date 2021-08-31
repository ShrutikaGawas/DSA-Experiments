//Program to accept student's details and print student's details with lowest percentage.
#include<stdio.h>
#include<stdlib.h>
struct Student
{
	int id;
	int age;
	float percentage;
};
int main()
{
	system("color 7");
	int i,n,min,m;
	struct Student *st;
	printf("\nEnter the number of Entries to be stored: ");
	scanf("%d",&n);
     st=(struct Student*)malloc(n*sizeof(struct Student));
	for(i=0;i<n;i++)
	{
		printf("\nEnter Student's ID: ");
		scanf("%d",&(st+i)->id);
		printf("Enter Age: ");
		scanf("%d",&(st+i)->age);
		printf("Enter Percentage: ");
		scanf("%f",&(st+i)->percentage);
		printf("\n");
	}
	printf("\n---------DETAILS----------\n");
	min=0;
	for(i=0;i<n;i++)
	{
		
		if(st->percentage > (st+i)->percentage)
		{  
		   st->percentage =(st+i)->percentage;
		}
	}
	printf("DETAILS OF STUDENT WITH LOW PERCENTAGE\n");
	printf("\nStudent's ID: %d",st->id);
    printf("\nStudent's Age: %d",st->age);
	printf("\nStudent's Percentage: %.2f",st->percentage);
}


