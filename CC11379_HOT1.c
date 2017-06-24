#include<stdio.h>

struct store
{
    char isbn[10];
    char title[10];
    float price;
    float disc;
    struct store *ptrnext;
};

struct store *headptr,*newptr,*currentptr,*previousptr;

int main()
{
    headptr = NULL;
    char ch;

    do {
        printf("\n\nwelcome to ABC BOOKSTORE\n");
        printf("\na - buy a book with begining");
        printf("\nb - buy a book with end");
        printf("\nd - list a book");
        printf("\nr - remove a book");
        printf("\nx - Exit book store");
        printf("\n\nEnter choice : ");
        scanf(" %c", &ch);
        ch = tolower(ch);

        switch (ch)
        {
            case 'a':add_book_beginning();break;
            case 'b':add_book_end();break;
            case 'd':display();break;
            case 'r':remove_book();break;
            case 'x':printf("\nBubye..Please come again..");break;
            default:printf("\nInvalid choice..");
                    system("\npause");
                    system("cls");break;
        }
    }while(ch!='x');
}
void add_book_beginning()
{
    newptr = (struct store*)malloc(sizeof(struct store));

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
    printf("\n\nEnter ISBN : ");
    scanf(" %s", &newptr->isbn);

    printf("\n\nEnter TITLE : ");
    scanf(" %s", &newptr->title);

    printf("\n\nEnter PRICE : ");
    scanf(" %f", &newptr->price);

    printf("\n\nEnter DISCOUNT : ");
    scanf(" %f", &newptr->disc);
}
void add_book_end()
{
    newptr = (struct store*)malloc(sizeof(struct store));

    printf("\n\nEnter ISBN : ");
    scanf(" %s", &newptr->isbn);

    printf("\n\nEnter TITLE : ");
    scanf(" %s", &newptr->title);

    printf("\n\nEnter PRICE : ");
    scanf(" %f", &newptr->price);

    printf("\n\nEnter DISCOUNT : ");
    scanf(" %f", &newptr->disc);

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
void display()
{
    if(headptr==NULL)
    {
        printf("\nBook List is empty..");
        system("\npause");
        system("\cls");
        return;
    }
    printf("\n\n\n\n-----------------------------------------------------------------------");
    printf("\n\t\tReceipt\n-----------------------------------------------------------------------");
    printf("\nISBN\tTITLE\tPRICE\tDISC");
    currentptr=headptr;
    do{
        printf("\n%s", currentptr->isbn);
        printf("\t%s", currentptr->title);
        printf("\tRM%.2f", currentptr->price);
        printf("\tRM%.2f", currentptr->disc);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
void remove_book()
{
    if(headptr==NULL)
    {
        printf("\nBook List is empty..");
        system("\npause");
        system("\cls");
        return;
    }
    else
    {
        currentptr = headptr;

        while(currentptr->ptrnext!=NULL)
        {
            previousptr=currentptr;
            currentptr=currentptr->ptrnext;
        }
        if(currentptr==headptr)
        {
            headptr=NULL;
            free(currentptr);
        }
        else
        {
            previousptr->ptrnext=NULL;

        }
    }
}

void remove_middle()
{
    char book_remove[20];

     if(headptr==NULL)
    {
        printf("\nBook List is empty..");
        system("\npause");
        system("\cls");
        return;
    }
    else
    {
        printf("\nEnter Book to delete : ");
        scanf(" %s", &book_remove);

        currentptr = headptr;

        while(currentptr->ptrnext!=NULL)
        {
            if(currentptr->title==book_remove)
            {
                break;
            }
            else
            {
                previousptr=currentptr;
            currentptr=currentptr->ptrnext;
            }
        }
        if(currentptr->title==book_remove)
        {
            if(currentptr==headptr)
            {
                headptr=currentptr->ptrnext;
                free(currentptr);
            }
            else
            {
                previousptr->ptrnext=currentptr->ptrnext;
                free(currentptr);
            }
        }
        else
        {
            printf("\nThe title is not in list..");
        }

        }
    }

void remove_book_begin()
{
    if(headptr==NULL)
    {
        printf("\nBook List is empty..");
        system("\npause");
        system("\cls");
        return;
    }
    else
    {
        currentptr = headptr;
        headptr=headptr->ptrnext;
        free(currentptr);
}
}
