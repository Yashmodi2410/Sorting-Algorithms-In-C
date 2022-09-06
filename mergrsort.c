#include<stdio.h>
#include<time.h>
#define MAX 50

double tc;
time_t start,end;

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high );

int main(){

    int i,n,arr[]={1, 10, 2, 3, 4, 1, 2, 100,23, 2};

    start=clock();
    partition(arr,0,n-1);
    printf("printing sorted elements\n");

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    tc=((double)(end-start)/CLOCKS_PER_SEC);
    printf("\n time efficiency of Mergesort is %f",tc);
    return 0;
}

void partition(int arr[],int low,int high){

    int mid;
    if(low<high){
        mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        mergeSort(arr,low,mid,high);
    }
}
void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
        if(arr[l]<=arr[m]){
            temp[i]=arr[l];
            l++;
        }
    else{
        temp[i]=arr[m];
        m++;
    }
    i++;
}
end=clock();

    if(l>mid){
        for(k=m;k<=high;k++){
            temp[i]=arr[k];
            i++;
        }
        end=clock();
    }
    else{
        for(k=l;k<=mid;k++){
            temp[i]=arr[k];
            i++;
        }
    end=clock();
    }

    for(k=low;k<=high;k++){
        arr[k]=temp[k];
    }
    end=clock();
}
