//Factorial (n) computation using recursion

#include <stdio.h>
#include <conio.h>

int main ()
{
int fact(int);
int number,factnum;

printf("\nEnter positive number: ");
scanf("%d",&number);
factnum=fact(number);
printf("\nFactorial number for %d\! = %d",number,factnum);

getch();
}

/*Recursive factorial*/

int fact(int number)
{
	if(number==0)  //stopping condition
     {
		return 1;
     }
	else
     {
	   return (number*fact(number-1));
     }
}
