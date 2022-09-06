#include<stdio.h>
#include<time.h>

double tc;
time_t start,end;

void quicksort(int arr[],int first,int last){

    int i, j, pivot, temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

      while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
            i++;
            while(arr[j]>arr[pivot])
            j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
}

int main(){

    int i,arr[]={1, 10, 2, 3, 4, 1, 2, 100,23, 2};

    int size = sizeof(arr)/sizeof(arr[0]);

    start = clock();

    quicksort(arr,0,size-1);

    end = clock();

    printf("printing sorted elements\n ");
    for(i=0;i<size;i++){
        printf(" %d",arr[i]);
    }

    tc=((double)(end-start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency of Quicksort is %f",tc);

   return 0;
}
