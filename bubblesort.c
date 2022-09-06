#include <stdio.h>
#include<time.h>

double tc;
time_t start,end;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    start = clock();

    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);

    end = clock();

    printf("Sorted array: \n");
    printArray(arr, n);

    tc=((double)(end-start)/CLOCKS_PER_SEC);
    printf("time efficiency is %f",tc);

    return 0;
}
