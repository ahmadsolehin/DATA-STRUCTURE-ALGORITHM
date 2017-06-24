#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAXSTACK 3

int top=-1; //top start at -1 because array start at 0  when the first push() is done
char stack[MAXSTACK];
char stack2[MAXSTACK];
int i;
char getpush,getpush2;
char ch;
void push(char,char);
void pop();
void display(int);
int main()
{
	do
	{

		printf("\n\n[-------Stack Menu-------]");
		printf("\nA - Push Stack");
		printf("\nB - Pop Stack");
		printf("\nD - Display Stack Content");
		printf("\nX - Exit Menu");
		printf("\nPlease enter choice: ");

		scanf(" %c",&ch);
		ch=toupper(ch);
		switch (ch)

		{
		case 'A': printf("\nPlease enter the number to push stack: ");
                scanf(" %s",&getpush);

                 printf("\nPlease enter the number to push stack: ");
                scanf("%s",&getpush2);

				  push(getpush,getpush2);
				  break;

		case 'B': printf("\nPop the stack");
				  pop();
				  break;

		case 'D': display(top);
				  break;

		case 'X': printf("\nExit stack menu");
				  break;

		default: printf("\nInvalid entry. Please select A, B, D, X\n");
		}
	}while (ch!='X');

   getch();

	return 0;
}



void push(char item,char ehem)
{
	if(top+1==MAXSTACK)  //Check for stack OVERFLOW
	{
      printf("\n");
		printf("\n!!! stack OVERFLOW - can't push stack !!!");
      return; //disallow further push operation by return to main menu
	}

	else
	{
		stack[++top]=item;//increment TOP variable and assign new item to topmost stack element.
		stack2[++top] = ehem;
		display(top);
      return;
	}
}

void pop()
{
	if (top<0) //Check for stack underflow
	{
      printf("\n");
		printf("\n!!! stack UNDERFLOW - can't pop stack !!!");
      return; //If stack underflow occurs, disallow further pop operation.
	}

	else
	{
		top=top-1; //If not, decrement TOP variable by one.
		display(top);
      return;
	}
}

void display(int list)
{
	printf("\nContents of stack: ");
	if(list==-1)
		printf("\nThe stack is now empty");
	else
	{
		for (i=0;i<=list;i++)
			printf("\nNumber at location stack %d = %s",i,stack[i]);
			printf("\conson at location stack %d = %s",i,stack2[i]);
	}
}
