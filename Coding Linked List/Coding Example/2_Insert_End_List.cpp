// Program to illustrates the insertion at the end of a linked list

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

struct number *headptr, *newptr, *currentptr;  //pointer that can point to a node

int main()
{
	char ch;
	int choice=TRUE;

	headptr=(struct number *)NULL;
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

   printf("\nEnter a number: ");
	scanf("%d",&newptr->number);

	if (headptr==(struct number *)NULL)//node is empty?
	  	{headptr=newptr; //first pointer point to first node
       newptr->ptrnext=(struct number *)NULL; //first node pointer point to null
      }

	else
	{
      currentptr=headptr;

		while(currentptr->ptrnext !=(struct number *)NULL)//search until last node
		{
            currentptr=currentptr->ptrnext; //point to next node
		}

      		currentptr->ptrnext=newptr; //last node point to new node
				newptr->ptrnext= NULL; //new node point to null
	}


}

void list_number()
{
	if (headptr==(struct number*)NULL) //empty list
	{
		printf("\nEmpty list");
		return;
	}

	currentptr=headptr;
	do
	{
		printf("\n\n%d",currentptr->number);
		printf("\n");
		currentptr=currentptr->ptrnext; //point to next node
	}while(currentptr !=(struct number *)NULL);
}



