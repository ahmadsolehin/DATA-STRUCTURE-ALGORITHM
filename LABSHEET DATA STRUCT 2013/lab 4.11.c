#include<stdio.h>

struct pokok
{
    int room;
    char student[20];
    struct pokok *ptrnext;
};
struct pokok *headptr,*newptr,*currentptr,*previousptr;

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
{int shuib;
    if(headptr==NULL)
    {
        printf("\nCan't delete..\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("\nEnter room number to delete : ");
        scanf(" %d", &shuib);
        currentptr=headptr;
        while(currentptr->ptrnext!=NULL)
        {
            if(currentptr->room==shuib)
            {
                break;
            }
            else
            {
            previousptr=currentptr;
            currentptr=currentptr->ptrnext;
            }
        }
        if(currentptr->room==shuib){
              if(currentptr==headptr)
        {
            headptr=currentptr->ptrnext;
            free(currentptr);
        }
        else
        {
            previousptr->ptrnext=currentptr->ptrnext;
            free(currentptr);
        }}
    }
}
void add_patient()
{
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
    printf("\n\nRoom Number\tStudent");
    currentptr=headptr;
    do{
        printf("\n%d", currentptr->room);
        printf("\t\t  %s", currentptr->student);
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
}
//sorry puan, saya cepat sgt nk submit hari tu.. :)//
