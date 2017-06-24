#include <stdio.h>
#include <conio.h>
#include <string.h>

struct parent   //structure name
{
   char name[30];
	int age;
}  ;

int main()
{

   struct parent father = {"Ali",50};
   struct parent mother = {"Aminah",40}; //assign value to structure variable

   printf("\nfather.name = %s",father.name);//accessing structure elemen
	printf("\nfather.age = %d",father.age);

   printf("\n\nmother.name = %s",mother.name);//accessing structure elemen
	printf("\nmother.age = %d",mother.age);



   getch();
}

