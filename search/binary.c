#include <stdio.h>
#include <stdlib.h>

int n, count = 0;

int binary(int *arr,int b, int e, int key)
{
    if (b <= e)
    {
        count++;
        int m = b + (e - b) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else
        {
            if (key > arr[m])
            {
                return binary(arr,m + 1, e, key);
            }
            else
            {
                return binary(arr,b, m - 1, key);
            }
        }
    }
    return -1;
}

void tester()
{
    int key;
    printf("Enter n :");
    scanf("%d", &n);
    int *arr=(int *)malloc(sizeof(int)*n);
    printf("Enter array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key : ");
    scanf("%d", &key);
    int f = binary(arr,0, n, key);
    printf("Fount at %d ", f);
}

void plotter(){
    FILE *f1,*f2,*f3;
    f1 = fopen("bib.txt","a");
    f2 = fopen("biw.txt","a");
    f3 = fopen("bia.txt","a");
    for(int i=2;i<1024;i*=2){
        int *arr=(int *)malloc(sizeof(int)*i);
        for(int j=0;j<i;j++){
            arr[j] = 5;
        }
        count=0;
        binary(arr,0,i,5);
        fprintf(f1,"%d\t%d\n",i,count);
        count = 0;
        binary(arr,0,i,10);
        fprintf(f2,"%d\t%d\n",i,count);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main(){
    plotter();
}