// //test_gprof.c

// #include<stdio.h>

// void func4(void)
// {
//     printf("\n Inside func4() \n");
//     for(int count=0;count<=0XFFFF;count++);
// }

// void func3(void)
// {
//     printf("\n Inside func3() \n");
//     for(int count=0;count<=0XFFFFFFF;count++);
// }

// void func2(void)
// {
//     printf("\n Inside func2() \n");

//     for(int count=0;count<=0XFFF;count++);

//     func3();
// }

// void func1(void)
// {
//     printf("\n Inside func1() \n");
//     for(int count=0;count<=0XFFFFFF;count++);

//     func2();
// }

// int main(void)
// {
//     printf("\n main() starts...\n");
//     for(int count=0;count<=0XFFFFF;count++);

//     func1();
//     func4();
//     printf("\n main() ends...\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    // int arr[] = {12, 17, 6, 25, 1, 5};

    int size = 1000000;

    // Declare an array of size 10000
    int arr[size];

    // Fill the array with random values between 0 and 100
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101; // Generates a random number between 0 and 100
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}