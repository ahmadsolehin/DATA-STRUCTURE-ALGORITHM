#include <stdio.h>
#include <conio.h>

struct country
{
	char name[30];
	int areacode;
};

struct position
{
	struct country north;
	struct country south;
};

struct position negara;

int main()
{
   printf("\nEnter country north name:");
   scanf("%s",&negara.north.name);
   printf("\nEnter country north areacode:");
   scanf("%d",&negara.north.areacode);

   printf("\nEnter country south name:");
   scanf("%s",&negara.south.name);
   printf("\nEnter country south areacode:");
   scanf("%d",&negara.south.areacode);


	printf("\nCOUNTRY UP NORTH\n");
	printf("Name: %s",negara.north.name);
	printf("\nArea code: %d \n",negara.north.areacode);

	printf("\nCOUNTRY DOWN SOUTH\n");
	printf("Name: %s",negara.south.name);
	printf("\nArea code: %d",negara.south.areacode);
   getch();
}

