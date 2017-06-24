 #include<stdio.h>
#include<conio.h>

struct node
{	int number;
    char event[20];
	struct node *ptrnext;
};

struct node *headptr, *newptr, *currentptr;  //pointer that can //point to a node
void main()
{	char ch;

	headptr=(struct node*)NULL;
      do
	{	printf("\n\n[-------Main Menu-------]");
		printf("\ne - Enter new event");
		printf("\nl - List all event");
		printf("\nx - Exit");
		printf("\n\nEnter choice: ");
		scanf(" %c",&ch);
		ch=tolower(ch);

		switch(ch)
	      {
                case 'e':addevent();break;
		        case 'l':display();break;
		        case 'x': printf("\nExit menu"); break;
                default: printf("\nInvalid entry. Please select  e, l, x\n");
		}
	}while (ch!='x');

   	getch();
	return;
}

void addevent()
{
    newptr = (struct node*)malloc(sizeof(struct node));

    if(headptr==NULL)
    {
        headptr=newptr;
        newptr->ptrnext=NULL;
    }
    else
    {
        newptr->ptrnext=headptr;
        headptr=newptr;
    }
    printf("\nenter room number : ");
    scanf("%d", &newptr->number);

    printf("\nenter event name : ");
    scanf("%s", &newptr->event);
}

void display()
{
    if(headptr==NULL)
    {
        printf("\nempty list!\n");
        system("pause");
        system("cls");
        return;
    }
    printf("\nRoom number\t    Event");
    currentptr=headptr;
    do{
        printf("\n%d", currentptr->number);
        printf("\t\t   %s", currentptr->event);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
