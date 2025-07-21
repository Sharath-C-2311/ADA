#include<stdio.h>
#include<stdlib.h>

int visited[100],graph[100][100],n,count=0;
int stack[100],r=-1;
void dfs(int v){
    visited[v] = 1;
    for(int i=0;i<n;i++){
        count++;
        if(!visited[i] && graph[v][i]){
            dfs(i);
        }
    }
    stack[++r] = v;
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
    printf("GRAPH :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",graph[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    printf("\nTOPO ORDER :");
    for(int i=r;i>=0;i--){
        printf("%d-->",stack[i]);
    }
}

void plotter(int n1){
    FILE *f1,*f2;
    f1 = fopen("tdfsb.txt","a");
    f2 = fopen("tdfsw.txt","a");
    for(n=4;n<=8;n++){
        if(n1==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j+1 || j==i+1){
                        graph[i][j] = 1;
                    }
                    else{
                        graph[i][j] = 0;
                    }
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i<j){
                        graph[i][j] = 1;
                    }
                    else{
                        graph[i][j] = 0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        if(n1==0){
            fprintf(f1,"%d\t%d\n",n,count);
        }
        else{
            fprintf(f2,"%d\t%d\n",n,count);
        }

    }
    fclose(f1);
    fclose(f2);
}

void main(){
    for(int i=0;i<2;i++){
        plotter(i);
    }
}
