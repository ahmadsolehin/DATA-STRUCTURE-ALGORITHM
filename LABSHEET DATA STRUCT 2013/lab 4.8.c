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
    int jep_sepahtu;

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
        printf("\nAfter what room number u want to enter : ");
        scanf(" %d", &jep_sepahtu);

        currentptr=headptr;

        while(currentptr!=NULL)
        {
            if(currentptr->room==jep_sepahtu)
            {
                break;
            }
            else
            {
                currentptr=currentptr->ptrnext;
            }
        }
        if(currentptr==NULL)
        {
            printf("\n\nThe room number u enter is invalid la...");
            return;
        }
        else
        {
            newptr->ptrnext=currentptr->ptrnext;
            currentptr->ptrnext=newptr;
        }
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
