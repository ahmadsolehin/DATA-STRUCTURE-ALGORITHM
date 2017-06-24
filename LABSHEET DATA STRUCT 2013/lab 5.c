#include<stdio.h>
#include<conio.h>


struct node
{	char ic[100];
    char name[30];
	struct node *ptrnext;
};

struct node *headptr, *newptr, *currentptr;  //pointer that can //point to a node
void main()
{	char ch;

	headptr=(struct node*)NULL;
      do
	{	printf("\n\n[-------Stack Menu-------]");
		printf("\nA - Push Stack");
		printf("\nB - Pop Stack");
		printf("\nD - Display Stack Content");
		printf("\nX - Exit Menu");
		printf("\nPlease enter choice: ");
		scanf(" %c",&ch);
		ch=toupper(ch);

		switch(ch)
	      {
                case 'A':push();break;
		        case 'B':pop();break;
                case 'D':display();break;
		        case 'X': printf("\nExit stack menu"); break;
                default: printf("\nInvalid entry. Please select  A, B, D, X\n");
                system("pause");
                system("cls");
		}
	}while (ch!='X');

   	getch();
	return;
}

void push()
{
    newptr = (struct node*)malloc(sizeof(struct node));\

    printf("\nenter name : ");
    scanf("%s", &newptr->name);

    printf("\nenter ic : ");
    scanf("%s", &newptr->ic);



    if(headptr==NULL)
    {
        headptr=newptr;
        newptr->ptrnext=NULL;
    }
    else
    {
        currentptr=headptr;

        while(currentptr->ptrnext!=NULL)
        {
            currentptr=currentptr->ptrnext;
        }
        currentptr->ptrnext=newptr;
        newptr->ptrnext=NULL;
    }
}

void pop()
{
    if(headptr==NULL)
    {
        printf("\nCan't delete!\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        currentptr=headptr;
        headptr=headptr->ptrnext;
        free(currentptr);
    }
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
    currentptr=headptr;
    do{
        printf("\n%s", currentptr->name);
        printf("\t%s", currentptr->ic);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
