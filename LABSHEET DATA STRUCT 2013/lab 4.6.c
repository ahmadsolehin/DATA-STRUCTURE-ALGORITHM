#include<stdio.h>

struct pesakit
{
    int room;
    int patient;
    struct pesakit *ptrnext;
};
struct pesakit *headptr,*newptr,*currentptr;

int main()
{
    char ch;
    do{
        printf("\ne - Enter new patient number's");
        printf("\nl - list all patient");
        printf("\nx - Exit");
        printf("\n\nEnter choice : ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'e':add_patient();break;
            case 'l':list_patient();break;
            case 'x':printf("\n\nExit..Bubye..");break;
            default:printf("\nInvalid..\n");
        }
    }while(ch!='x');

}
void add_patient()
{
    newptr = (struct pesakit*)malloc(sizeof(struct pesakit));

    printf("\nEnter room number : ");
    scanf(" %d", &newptr->room);

    printf("Enter patient number : ");
    scanf(" %d", &newptr->patient);

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
void list_patient()
{
    if(headptr==NULL)
    {
        printf("\nList empty..\n");
        system("pause");
        system("cls");
        return;
    }
    printf("\n\nRoom Number\tPatient Number");
    currentptr=headptr;
    do{
        printf("\n%d", currentptr->room);
        printf("\t\t  %d", currentptr->patient);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
