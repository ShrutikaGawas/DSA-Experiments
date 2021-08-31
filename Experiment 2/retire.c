//Program to find the date of retirement of the employee.
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct date{
	int date;
	int month;
	int year;
};
struct Employee
{
  int id;
  struct date join;
  struct date dob;
  struct date ret;
  	struct date cur;                      
};
int main()
{
	system("color 7");
    struct Employee *e=(struct Employee*)malloc(sizeof(struct Employee));
    printf("\nEnter Employee ID: ");
	scanf("%d",&e->id);
	printf("Enter Date of Joining in DD-MM-YYYY format: ");
	scanf("%d-%d-%d",&e->join.date,&e->join.month,&e->join.year);
	printf("Enter Date of Birth: ");
	scanf("%d-%d-%d",&e->dob.date,&e->dob.month,&e->dob.year);
	

	printf("\n\n---------DETAILS----------\n\n");
	
		printf("\nEmployee ID: %d",e->id);
		printf("\nDate of Joining: %d-%d-%d",e->join.date,e->join.month,e->join.year);
		printf("\nDate of Birth: %d-%d-%d",e->dob.date,e->dob.month,e->dob.year);
	int join_age;
	 SYSTEMTIME td;      //point to store today's date
    GetLocalTime(&td);
	e->ret.year = e->dob.year + 65;
    e->ret.month = e->dob.month;
    
	if((e->ret.year > td.wYear) && (e->join.year < td.wYear) && (e->dob.year < td.wYear))
    {
        join_age = e->join.year - e->dob.year;
        if(join_age >= 18)
        {
            if((e->join.month < e->dob.month)&&(join_age == 18))
                printf("\nNot eligible. Age criteria not met.");
            else if (e->dob.month==1 || e->dob.month==3 || e->dob.month==5 || e->dob.month==7 || 
                     e->dob.month==8 || e->dob.month==10 ||e->dob.month==12)
                     e->ret.date = 31;
            else
            {
                if(e->dob.month == 2)
                    e->ret.date = 28;
                else
                    e->ret.date = 30;
            }
        } 
        printf("\n\nEmployee will retire at the age of 65");
        printf("\nDate of retirement: %d/%d/%d\n", e->ret.date, e->ret.month, e->ret.year);
        if(e->ret.month >td.wMonth)
            printf("\nRemaining days are: %d days, %d months, %d years", e->ret.date-td.wYear, 
                                                e->ret.month, e->ret.year-td.wYear-1);
        else
        {
            e->ret.month = 12-td.wMonth+ e->dob.month;
            printf("\nRemaining days are: %d days, %d months, %d years",e->ret.date-td.wDay, 
                                               e->ret.month, e->ret.year-td.wYear-1);
        }
    }
    else
    {
        printf("\nAge criteria failed! You may be younger than the required age.");
    }
	
}
