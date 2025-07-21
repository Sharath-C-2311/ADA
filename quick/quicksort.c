#include<stdio.h>
#include<stdlib.h>

int count = 0;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick(int *arr,int b,int e){
    if(b<e){
    int i=b;
    int j=e+1;
    int p=arr[b];
    do{
        do
        {
            i++;
            count+=1;
        } while (i<=e && arr[i]<p);
        
        do{
            j--;
            count+=1;
        }while(j>=b && arr[j]>p);

        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }while(i<j);

    swap(&arr[j],&arr[b]);
    quick(arr,b,j-1);
    quick(arr,j+1,e);
}
}


void main(){
    
    // int n,arr[100];
	// printf("\nEnter number of elements : ");
	// scanf("%d",&n);
	// printf("\nenter element : ");
	// for(int i=0;i<n;i++){
	// 	scanf("%d",&arr[i]);
	// }
	// printf("\nBefore selection sort : \n");
	// for(int i=0;i<n;i++){
	// 	printf("%d\t",arr[i]);
	// }
	
	// quick(arr,0,n-1);
	
	// printf("\nAfter selection sort :\n");
	// for(int i=0;i<n;i++){
	// 	printf("%d\t",arr[i]);
	// }
    int *arr;
    FILE *f1 = fopen("best.txt","a");
    FILE *f2 = fopen("worst.txt","a");
    for(int i=4;i<1034;i*=2){
        arr = (int *)malloc(sizeof(int)*i);
        for(int j=0;j<i;j++){
            arr[j]=5;
        }
        count=0;
        quick(arr,0,i-1);
        fprintf(f1,"%d\t%d\n",i,count);
        count=0;
        for(int j=0;j<i;j++){
            arr[j] = i-j;
        }
        quick(arr,0,i-1);
        fprintf(f2,"%d\t%d\n",i,count);
        free(arr);
    }
    fclose(f1);
    fclose(f2);
}