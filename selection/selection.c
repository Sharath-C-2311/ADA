#include<stdio.h>
#include<stdlib.h>

void select(int *arr,int n){
	for(int i=0;i<n-1;i++){
		int min = arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[j]<min){
				int temp = min;
				min = arr[j];
				arr[j] = temp;
			}
		}
		arr[i] = min;
	}
}

void main(){
	int n,arr[100];
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	printf("\nenter element : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nBefore selection sort : \n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	select(arr,n);
	
	printf("\nAfter selection sort :\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}