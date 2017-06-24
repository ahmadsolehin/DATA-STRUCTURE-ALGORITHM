#include <stdio.h>
#include <conio.h>

void recursion (int);

main()
{
int n;
printf("enter the number of star :");
scanf("%d",&n);
recursion (n);

getch();
}

void recursion (int n)
{
    int i;
if (n==1)
{
    printf("*\n");
}
else
{

  for(i=0;i<n;i++)
    printf("*");
            printf("\n");

    recursion(n-1);
}

}
