#include <stdio.h>
#include <stdlib.h>

int q[100], f = 0, r = 0, graph[100][100], visit[100], dfs[150], n, count = 0;

void bfs(int v)
{
    q[f] = v;
    int k = 0;
    while (f <= r)
    {
        int i = q[f++];
        dfs[k++] = i;
        visit[i] = 1;
        for (int j = 0; j < n; j++)
        {
            count++;
            if (graph[i][j] && !visit[j])
            {
                q[++r] = j;
                visit[j] = 1;
            }
        }
    }
}

void tester()
{
    int i = 0, dfs[100], k = 0, visit[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }

    bfs(0);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", dfs[i]);
    }
}

void plotter(int n2)
{
    FILE *f1, *f2;
    f1 = fopen("bfsb.txt", "a");
    f2 = fopen("bfsw.txt", "a");
    for (int n1 = 4; n1 <= 8; n1++)
    {
        if (n2 == 0)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
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
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    if (i == j)
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        graph[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n1; i++)
        {
            visit[i] = 0;
        }
        count = 0;
        n = n1;
        f = 0;
        r = 0;
        for (int i = 0; i < n1; i++)
        {
            if (!visit[i])
                bfs(0);
        }
        if (n2 == 0)
        {
            fprintf(f1, "%d\t%d\n", n1, count);
        }
        else
        {
            fprintf(f2, "%d\t%d\n", n1, count);
        }
    }
    fclose(f1);
    fclose(f2);
}

void main()
{
    for (int i = 0; i < 2; i++)
    {
        plotter(i);
    }
}
