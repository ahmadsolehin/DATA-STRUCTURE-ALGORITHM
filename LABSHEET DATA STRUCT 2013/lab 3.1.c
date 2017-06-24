#include<stdio.h>
#include<conio.h>


struct info
{
    char name[30];
    char id[8];
    char course[20];
    char title[20];
    char field[20];
    char sv[20];
};
void main()
{
    int numofstd,i;
    struct info std1[10]; //i assume of limit 10 student

    printf("\nenter number of student : ");
    scanf("%d", &numofstd);

    for(i=0;i<numofstd;i++)
    {
        printf("\n\nEnter name :\t");
        scanf("%s", &std1[i].name);

        printf("\nEnter matrix id :\t");
        scanf("%s", &std1[i].id);

        printf("\nEnter course :\t");
        scanf("%s", &std1[i].course);

        printf("\nEnter project title :\t");
        scanf("%s", &std1[i].title);

        printf("\nEnter field :\t");
        scanf("%s", &std1[i].field);

        printf("\nEnter supervisor :\t");
        scanf("%s", &std1[i].sv);
    }


    //the output
    printf("\n\n\tUNDERGRADUATE PROJECT RECORD SYSTEM\n");

    for(i=0;i<numofstd;i++)
    {
        printf("\nStudent’s Name : %s", std1[i].name);
        printf("\nMatrix ID: %s", std1[i].id);
        printf("\nCourse : %s", std1[i].course);
        printf("\nProject’s Title:  %s", std1[i].title);
        printf("\nField : %s", std1[i].field);
        printf("\nSupervisor : %s", std1[i].sv);
        printf("\n\n------------------------------");
    }
}
