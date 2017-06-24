/*Factorial (n) computation  using iteration*/

#include <stdio.h>
#include <conio.h>

void main ()
{
int fact (int);
int number,factnum;

printf("\nEnter a positive number: ");
scanf("%d",&number);
factnum=fact(number);
printf("\nFactorial number for %d\! = %d",number,factnum);

getch();
}

/*Iterative factorial*/
 
int fact (int number)
{  int i,fact = 1;

   for (i=number;i>1;i--)
	{
    fact=fact*i;
	}

	return fact;
}
