#include <stdio.h>
#include <conio.h>
#include <string.h>

struct student    //structure name
{
	char id[10];      // structure member
   char name[25];
	int age;
}  ;

int main()
{

   struct student stud_1 = {"123","Atikah",16};
   struct student stud_2 = {" ","Fatin"}; //assign value to structure variable

   printf("\nstud_1.name = %s",stud_1.name);//accessing structure elemen
	printf("\nstud_1.id = %s",stud_1.id);

   printf("\n\nstud_2.name = %s",stud_2.name);
   printf("\nstud_2.age = %d",stud_2.age);
   printf("\nstud_2.id = %s",stud_2.id);

   strcpy(stud_2.id,"456");  //modify the value of structure member
   stud_2.age = 14;

   printf("\n\nstud_2.name = %s",stud_2.name);
   printf("\nstud_2.age = %d",stud_2.age);
   printf("\nstud_2.id = %s",stud_2.id);


   getch();
}

