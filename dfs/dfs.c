#include <stdio.h>

int graph[40][40], n, visited[40] = {0}, acyclic = 1, count = 0;

void createGraph()
{
    printf("No. of vertices>> ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void dfs(int v, int p)
{
    visited[v] = 1;
    printf("%d-->", v);
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("count %d\n", count);
        if (graph[v][i] && !visited[i])
        {
            dfs(i, v);
        }

        else if (graph[v][i] && visited[i] && i != p)
        {
            acyclic = 0;
        }
    }
}

void tester()
{
    int i, count = 0, flag = 1;

    createGraph();

    dfs(0, -1);

    if (count != n)
    {
        printf("Disconnected part :");
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                flag = 0;
                dfs(i, -1);
                printf("\n");
            }
        }
    }

    (flag) ? printf("\nConnected Graph\n") : printf("\nGraph not connected!\n");
    (acyclic) ? printf("Acyclic Graph\n") : printf("Graph not acyclic!\n");
}

void plotter(int n1)
{
    FILE *f1, *f2;
    f1 = fopen("dfsb.txt", "a");
    f2 = fopen("dfsw.txt", "a");
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

        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1);
            }
        }
        if (n1 == 0)
        {
            fprintf(f1, "%d\t%d\n", n, count);
        }
        else
        {
            fprintf(f2, "%d\t%d\n", n, count);
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