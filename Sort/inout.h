#include<stdio.h>
void in(int size,int *arry)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arry[i]);
    }
}

void out(int size,int *array)
{
    
    for (int i=0;i<size;i++)
    {
        printf("%d  ",array[i]);
    }
    
}

