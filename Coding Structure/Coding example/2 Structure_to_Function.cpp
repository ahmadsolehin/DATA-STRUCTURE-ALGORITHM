#include <stdio.h>
#include <conio.h>

struct student    //structure name
{
	char id[10];      // structure member
   char name[25];
	int age;
}  ;

void display (student); //prototypes

int main()
{
   struct student stud_1 = {"123","Hidayah",16};


   display(stud_1);  //pass structure variable to function
   getch();
}

void display(student first_stud)//function definition
{
	printf("\nstud_1.name = %s",first_stud.name);
	printf("\nstud_1.id = %s",first_stud.id);
}
