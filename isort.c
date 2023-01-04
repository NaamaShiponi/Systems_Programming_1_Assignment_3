#include <stdio.h>
#include "isort.h"

int main()
{
    int arr[ARRAY];
    int num=0;
    for (int i = 0; i <ARRAY ; i++)
    {
        scanf("%d",&num);
        *(arr+i)=num;
    }
    

    insertion_sort(arr , ARRAY);
    for(int i = 0; i<ARRAY; i++)
    {
        if(i<ARRAY-1)
        {
            printf("%d,", *(arr+i));
        }
        else
        {
            printf("%d\n", *(arr+i));
        }
        
    }
    // fclose(fp);
    return 0;
}

int shift_element(int* arr, int i)
{
    for(int j = i; j>0; j--)
    {
        *(arr+j+1) = *(arr+j);
    }
    return 0;
}

int insertion_sort(int* arr , int len)
{
    for(int i=1; i<len; i++)
    {
        int j=i-1;
        if(*(arr+j)>*(arr+i))
        {
            do{
                j--;
            }while ((j>=0) & (*(arr+j)>*(arr+i)));

            int alemnt_in_place_i = *(arr+i);
            shift_element(arr+j, (i-(j+1)));
            *(arr+j+1) = alemnt_in_place_i;
        }
    }
    return 0;
}