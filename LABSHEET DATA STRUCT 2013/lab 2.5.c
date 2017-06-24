#include<stdio.h>

int main()
{
int num,sum;

printf("Enter the value of num: ");
scanf(" %d",&num);

sum = getSum(num);

printf("Sum of n numbers: %d", sum);

return 0;
}

int getSum(int num)
{
if(num == 1)
return 1;

return (num + getSum(num-1));
}
