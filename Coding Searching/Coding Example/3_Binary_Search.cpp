//Binary Search
#include <stdio.h>
#include <conio.h>

void binary_search(int [],int, int);

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

	/*Read in the search value for binary search */
	printf("\n\nEnter the search value for binary search: ");
	scanf("%d",&searchValue);

	/*Called the binary search function */
	binary_search(data, numData, searchValue);



   getch();
}


void binary_search(int data[],int size, int searchValue)
{
	int first=0;
	int last=size - 1;
	int mid;
   int count=0;

	while(first<=last)
	{
      count++;
		mid=(first+last)/2;
	   printf("\nValue for mid: %d",mid);

		if(searchValue==data[mid])
			{	printf("\n\nSearch value found !");
         	printf("\nNumber of comparison: %d",count);
				return;
			}
		else
			if(searchValue<data[mid])
				last=mid - 1;
			else
				first=mid + 1;
	}

	printf("\n\nSorry, no match found !");
   printf("\nNumber of comparison: %d",count);
   return;
}
