#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main()
{
    int *arr = NULL;

    int len = 0;
    printf("Array len? \n");
    readInteger(&len);

    //1.
    //arr = (int *)malloc(len * sizeof(int));
    //5.
    //arr = (int *)calloc(len, sizeof(int));

    //9.
    arr = arrayInit(len);
    if (arr == NULL)
        return EXIT_FAILURE; //Boa prática

    //2.
    printf("arr addr = %p \n", arr);
    printArray(arr, len);

    //6.
    //for (int i = 0; i < len; i++)
    //{
    //    arr[i] = (i + 1);
    //}
    //printArray(arr, len);

    //7.
    int *newArray = (int *)realloc(arr, len * 2 * sizeof(int));
    if (newArray != NULL)
    {
        arr = newArray;
        len *= 2;
    }
    for (int i = len / 2; i < len; i++)
    {
        arr[i] = (i + 1);
    }

    printArray(arr, len);

    //4.
    //free(arr);
    //9.
    arrayFree(arr);
    return EXIT_SUCCESS;
}