// Program to illustrates the insertion into a linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void new_number();
void list_number();

struct number
{
	int number;
	struct number *ptrnext;
};

struct number *firstptr, *newptr;

void main()
{
	char ch;
	int choice=TRUE;

	firstptr=(struct number *)NULL;
	while(choice==TRUE)

	{
		printf("\n\ne - Enter a number");
		printf("\nl - List all numbers");
		printf("\nx - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		switch(ch)
		{
		case 'e':new_number();break;
		case 'l':list_number();break;
		case 'x': choice=FALSE; break;

		default: printf("\nEnter only one from the above");
		}
	}
}

void new_number()
{
  newptr=(struct number *)malloc(sizeof (struct number)); // pointer to a new
  																			//	memory allocation
   
	if (firstptr==(struct number *)NULL)//node is empty?
	  	{firstptr=newptr; //first pointer point to first node
       newptr->ptrnext=(struct number *)NULL; //first node pointer point to null 
      }

	else
	{
	   newptr->ptrnext=firstptr;// new node pointer point to previous first node
		firstptr=newptr; // head point to new node,new node become first node
	}

	printf("\nEnter a number: ");
	scanf("%d",&newptr->number);

}

void list_number()
{
	if (firstptr==(struct number*)NULL) //empty list
	{
		printf("\nEmpty list");
		return;
	}


	newptr=firstptr;
	do
	{
		printf("\n\n%d",newptr->number);
		printf("\n");
		newptr=newptr->ptrnext; //point to next node
	}while(newptr !=(struct number *)NULL);
}



