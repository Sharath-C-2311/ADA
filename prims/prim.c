#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost[40][40], visited[40], n;
    printf("Enter size : ");
    scanf("%d", &n);
    printf("Enter matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0){
                cost[i][j] = 9999;
            }
        }
        visited[i] = 0;
    }
    int e=0,a,b,min_c=0;
    visited[0] = 1;
    while(e<n-1){
        int min=9999;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(cost[i][j] < min && !visited[j]){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        visited[b] = 1;
        printf("%d -> %d\n",a,b);
        e++;
        min_c+=cost[a][b];
    }
    printf("\nmin cost : %d\n",min_c);
}