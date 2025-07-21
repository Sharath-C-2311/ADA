#include<stdio.h>
#include<stdlib.h>

int n,graph[50][50],visited[50],dist[50];

void dij(int v){
    
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    visited[v] = 1;
    
    for(int i=0;i<n;i++){
        dist[i] = graph[v][i];
    }

    dist[v]=0;
    
    int c=0;
    int ind;
    while(c<n){
        int min=999;
        c++;
        for(int i=0;i<n;i++){
            if(dist[i]<min && !visited[i]){
                min = dist[i];
                ind=i;
            }
        }
        visited[ind] = 1;

        for(int i=0;i<n;i++){
            if(dist[i]>dist[ind]+graph[ind][i]){
                dist[i] = dist[ind]+graph[ind][i];
            }
        }
    }
}

int main(){
    printf("Enter number n :");
    scanf("%d", &n);
    printf("Enter elements :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j]==0){
                graph[i][j]=999;
            }
        }
    }
    printf("\nn=%d\n",n);
    dij(0);
    for(int i=0;i<n;i++){
        printf("0->%d\t%d\n",i,dist[i]);
    }
}