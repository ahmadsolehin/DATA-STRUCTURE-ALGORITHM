#include<stdio.h>

struct pokok
{
    int room;
    char student[20];
    struct pokok *ptrnext;
};
struct pokok *headptr,*newptr,*currentptr;

int main()
{
    char ch;
    do{
        printf("\ne - Enter new student's");
        printf("\nl - list all student");
        printf("\nd - delete a student");
        printf("\nx - Exit");
        printf("\n\nEnter choice : ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'e':add_patient();break;
            case 'l':list_patient();break;
            case 'd':delete_stud();break;
            case 'x':printf("\n\nExit..Bubye..");break;
            default:printf("\nInvalid..\n");
                    system("pause");
                    system("cls");break;
        }
    }while(ch!='x');

}
void delete_stud()
{
    if(headptr==NULL)
    {
        printf("\nCan't delete..\n");
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
void add_patient()
{
    int jep_sepahtu;

    newptr = (struct pokok*)malloc(sizeof(struct pokok));

    printf("\nEnter room number : ");
    scanf(" %d", &newptr->room);

    printf("Enter student name : ");
    scanf(" %s", &newptr->student);

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
    printf("\n\nRoom Number\tStudent");
    currentptr=headptr;
    do{
        printf("\n%d", currentptr->room);
        printf("\t\t  %s", currentptr->student);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
