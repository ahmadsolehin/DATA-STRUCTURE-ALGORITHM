//Linear Sequential Search
#include <stdio.h>
#include <conio.h>

void seq_search(int [],int, int);

int main()
{
	int numData = 0, data[10000],searchValue;

	/*Read in values from data.txt*/

   FILE *input; /*declare a file */
	input = fopen("data.txt", "r"); /*read the file*/

   printf("The random numbers in data.txt are:\n\n");

   while (fscanf(input,"%d", &data[numData])!= EOF) /* read from file*/
	{
		printf("%d\t",data[numData]); /*display to the screen */
   	numData++;
	}

	/*Read in the search value for linear sequential search */
	printf("\n\nEnter the search value for linear sequential search: ");
	scanf("%d",&searchValue);

	/*Linear sequential search for element */
	seq_search(data,numData, searchValue); //function for linear seq search

   fclose(input);/*close the file*/

   getch();
}


void seq_search(int data[],int size, int searchValue)
{
	int i, count=0;

	for(i=0;i<size;i++)
	{
   	count++;

		if(data[i]==searchValue)
		{
			printf("\nSearch value found !");
         printf("\nNumber of comparison: %d",count);
			return;
		}
	}

	printf("\nSorry, no match found");
   printf("\nNumber of comparison: %d",count);
	return;
}
