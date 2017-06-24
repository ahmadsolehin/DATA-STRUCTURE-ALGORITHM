#include<stdio.h>

int main(){

    int num,sum;

    printf("Enter number : ");
    scanf("%d",&num);

    sum = getSum(num);

    printf("Sum of the numbers: %d",sum);

    return 0;
}

int getSum(num){

    int sum=0;

    while(num>0){
         sum = sum + num;
         num--;
    }

    return sum;
}

