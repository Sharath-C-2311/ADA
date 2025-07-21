#include<stdio.h>
#include<stdlib.h>

int arr[1000],n,count=0;

int search(int k,int n){
    for(int i=0;i<n;i++){
        count++;
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}

int tester(){
    printf("Enter n :");
    scanf("%d",&n);
    printf("Enter array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter key : ");
    scanf("%d",&key);
    printf("key found at %d\n",search(key,n));
}

void plotter(){
    FILE *f1,*f2,*f3;
    f1=fopen("lb.txt","a");
    f2=fopen("lw.txt","a");
    f3=fopen("la.txt","a");
    for(int i=2;i<1024;i*=2){
        for(int j=0;j<i;j++){
            arr[j]=5;
        }
        count=0;
        search(5,i);
        fprintf(f1,"%d\t%d\n",i,count);
        count = 0;
        search(10,i);
        fprintf(f2,"%d\t%d\n",i,count);
        count=0;
        for(int j=0;j<i;j++){
            arr[j]=rand();
        }
        int r = rand()%i;
        search(arr[r],i);
        fprintf(f3,"%d\t%d\n",i,count);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main(){
    plotter();
}