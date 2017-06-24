//Ordered Sequential Search
#include <stdio.h>
#include <conio.h>

void orderseq_search(int [],int, int);

int main()
{
	int numData=0,x,y,temp;
   int data[10000],searchValue;

	/*Read in values from data.txt*/

   FILE *input; /*declare a file */
	input = fopen("data.txt", "r"); /*read the file*/

   printf("The random numbers in data.txt are:\n\n");

   while (fscanf(input,"%d", &data[numData])!= EOF) /* read from file*/
	{
		printf("%d\t",data[numData]); /*display to the screen */
   	numData++;
	}


	/*Sort list in ascending order*/
	for(x=0; x<numData;x++)
	  {	for(y=x+1; y<numData; y++)
		 	{	if(data[x]>data[y])
				{
				temp=data[x];
				data[x]=data[y];
				data[y]=temp;
				}
       	}
     }

   /*Display (sorted) the list of numbers entered earlier by user */
	printf("\nSorted list of element entered: \n");
	for(int i=0; i<numData; i++)
		printf("%d\t",data[i]);

	/*Read in the search value for ordered Sequential search */
	printf("\n\nEnter the search value for ordered sequential search: ");
	scanf("%d",&searchValue);

	/*order sequential search for element */
	orderseq_search(data, numData, searchValue);

   getch();
}


void orderseq_search(int data[],int size, int searchValue)
{
	int i,count=0;
	i=size-1;

	while(i>=0)
	{
      count++;

		if(data[i] == searchValue)
		{
			printf("\nSearch value found !");
         printf("\nNumber of comparison: %d",count);
			return;
		}

		else if(data[i]<searchValue)  //terminate the search if the data item < keyfield
		{
			printf("\nSorry, no match found");
         printf("\nNumber of comparison: %d",count);
			return;
		}
			i--; //reduce the size of array for searching
	}

	printf("\nSorry, no match found.");
   printf("\nNumber of comparison: %d",count);
	return ;

}
