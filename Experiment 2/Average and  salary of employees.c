//Program to accept details of n employees and compute the average salary.
#include<stdio.h>
#include<stdlib.h>
struct Employee
{
	char name[15];
	int age;
	int salary;
	char qualification[30];
};
int main()
{
	system("color 7");
	struct Employee *e;
	int i,n,sum=0;
	float avg=0;
	printf("\n Enter the number of Entries to be stored: ");
	scanf("%d",&n);
	e=(struct Employee*)malloc(n*sizeof(struct Employee));
	for(i=1;i<=n;i++)
	{
		printf("\n Enter Name: ");
		scanf("%s",&(e+i)->name);
		printf("Enter Age: ");
		scanf("%d",&(e+i)->age);
		printf("Enter Qualification: ");
		scanf("%s",&(e+i)->qualification);
		printf("Enter Salary: ");
		scanf("%d",&(e+i)->salary);
	}
	printf("\n\n---------DETAILS----------\n\n");
	for(i=1;i<=n;i++)
	{
		printf("\nName: %s",(e+i)->name);
		printf("\nAge: %d",(e+i)->age);
		printf("\nQualification: %s",(e+i)->qualification);
		printf("\nEnter Salary: %d",(e+i)->salary);
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		sum=sum+(e+i)->salary;
	}
		avg=(float)sum/(float)n;
		printf("\n\nTHE AVERAGE SALARY: %f",avg);
}
