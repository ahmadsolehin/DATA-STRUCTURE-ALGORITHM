#include<stdio.h>
#include<conio.h>

struct birthday
{
    int day;
    int month;
    int year;
};
struct newborn
{
    char name[20];
    char sex[10];
    struct birthday dob;      //nested structure
};
struct parent
{
    char name[20];
    int age;
};
struct parent father[10],mother[10];
int main()
{
    struct newborn baby[10];

    int num,i;
    printf("enter number : "); //limit only 10
    scanf(" %d", &num);

    for(i=0;i<num;i++)
    {
        printf("\n\n\nBaby name : ");
        scanf(" %s", &baby[i].name);

        printf("\nSex : ");
        scanf(" %s", &baby[i].sex);

        printf("\nBirthday : ");
        scanf(" %d.%d.%d", &baby[i].dob.day,&baby[i].dob.month, &baby[i].dob.year);

        printf("\nEnter father name : ");
        scanf("%s", &fa3ther[i].name);

        printf("\nEnter father age : ");
        scanf("%d", &father[i].age);

        printf("\nEnter mother name : ");
        scanf("%s", &mother[i].name);

        printf("\nEnter mother age : ");
        scanf("%d", &mother[i].age);
    }

    printf("\n\n\nNEW BORN BABY IN KUANTAN HOSPITAL\n");
    for(i=0;i<num;i++)
    {
        printf("\nBaby name : %s", baby[i].name);
        printf("\nBirthday : %d/%d/%d", baby[i].dob.day,baby[i].dob.month,baby[i].dob.year);
        printf("\n\nFather name : %s", father[i].name);
        printf("\nFather age : %d", father[i].age);
        printf("\n\nMother name : %s", mother[i].name);
        printf("\nMother age : %d", mother[i].age);
        printf("\n--------------------------------");
    }
}
