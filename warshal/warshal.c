#include<stdio.h>
#include<stdlib.h>

int n,graph[100][100],count=0;

void warshal(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(graph[i][k]){
                for(int j=0;j<n;j++){
                    count++;
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
    }
}

void tester(){
    printf("Enter number n :");
    scanf("%d",&n);
    printf("Enter elements :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    warshal();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}


void plotter(int c){
    FILE *f1,*f2;
    f1=fopen("wb.txt","a");
    f2=fopen("ww.txt","a");
    for(n=2;n<12;n++){
        if(c==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                        graph[i][j]=1;
                    }
                    else{
                        graph[i][j]=0;
                    }
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    graph[i][j]=0;
                }
            }
            for(int i=0;i<n-1;i++){
                graph[i][i+1]=1;
            }
            graph[n-1][0]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d\t",graph[i][j]);
            }
            printf("\n");
        }
        count=0;
        warshal();
        if(c==0){
            fprintf(f2,"%d\t%d\n",n,count);
        }
        else{
            fprintf(f1,"%d\t%d\n",n,count);
        }
    }
}


int main(){
    for(int i=0;i<2;i++){
        plotter(i);
    }
}