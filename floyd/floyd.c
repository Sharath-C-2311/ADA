#include <stdio.h>
#include <stdlib.h>

int graph[100][100], n, count = 0;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void floyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = graph[i][k];
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] > temp)
                {
                    count++;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int tester()
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
    floyd();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void plotter()
{
    FILE *f1 = fopen("f.txt", "a");
    for (n = 2; n < 12; n++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    graph[i][j] = 0;
                }
                else
                {
                    graph[i][j] = rand();
                }
            }
        }
        count = 0;
        floyd();
        fprintf(f1, "%d\t%d\n", n, count);
    }
    fclose(f1);
}

void main()
{
    plotter();
}