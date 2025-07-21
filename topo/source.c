#include <stdio.h>
#include <stdlib.h>

int graph[100][100], in[100], count = 0, n, visit[100], stack[100], top = -1;

void src()
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            stack[++top] = i;
        }
    }
    int completed = 0;
    while (completed < n)
    {
        int u = stack[top--];
        completed++;
        printf("%d-->", u);
        for (int i = 0; i < n; i++)
        {
            count++;
            if (graph[u][i] == 1)
            {
                graph[u][i] = 0;
                in[i]--;
                if (in[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

void test()
{

    printf("Enter number n :");
    scanf("%d", &n);
    printf("Enter elements :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("GRAPH :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        in[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
                in[j]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    printf("\nTOPO ORDER :");
    src();
}

void plotter(int n1)
{
    FILE *f1,*f2;
    f1 = fopen("sb.txt","a");
    f2 = fopen("sw.txt","a");
    
    for (n = 4; n <= 8; n++)
    {
        if (n1 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j + 1 || j == i + 1)
                    {
                        graph[i][j] = 1;
                    }
                    else
                    {
                        graph[i][j] = 0;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i < j)
                    {
                        graph[i][j] = 1;
                    }
                    else
                    {
                        graph[i][j] = 0;
                    }
                }
            }
        }
        count = 0;
        top=-1;

        for (int i = 0; i < n; i++)
        {
            in[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j])
                    in[j]++;
            }
        }
        src();
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
    printf("main");
    for(int i=0;i<2;i++){
        printf("here main");
        plotter(i);
    }
}
