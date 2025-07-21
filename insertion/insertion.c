#include<stdio.h>
#include<stdlib.h>

void insert(int *arr,int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int k = arr[i];
        while(j>=0 && arr[j]>k){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}


void main(){
    int arr[100],n;
    printf("Enter number n :");
    scanf("%d",&n);
    printf("Enter elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Elements before sorting :");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    insert(arr,n);
    
    printf("\nElements after insertion sort :");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
