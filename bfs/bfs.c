#include <stdio.h>
#include <stdlib.h>

int count = 0;
int graph[40][40], visited[40] = {0}, n, f = 0, r = 0, ans[40], q[40], parent[40], acyclic = 1, con = 1, k = 0;

void bfs(int v)
{
    f = 0;
    r = 0;
    visited[v] = 1;
    q[f] = v;
    k = 0;
    while (f <= r)
    {
        int j = q[f++];
        ans[k++] = j;
        for (int i = 0; i < n; i++)
        {
            count++;
            printf("  %d", count);
            if (graph[j][i] && !visited[i])
            {
                parent[i] = j;
                visited[i] = 1;
                q[++r] = i;
            }
            else if (graph[j][i] && visited[i] && i != parent[j])
            {
                acyclic = 0;
            }
        }
    }
}

void plotter(int n2)
{
    FILE *f1, *f2;
    f1 = fopen("b.txt", "a");
    f2 = fopen("w.txt", "a");

    for (n = 4; n <= 8; n++)
    {
        if (n2 == 0)
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
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }

        bfs(0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(i);
            }
        }

        if (n2 == 0)
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

void tester()
{

    printf("Enter n : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    bfs(0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            con = 0;
        }
    }

    (con) ? printf("Connected graph\n") : printf("Disonnected graph\n");
    (acyclic) ? printf("Acyclic graph\n") : printf("Cyclic graph\n");
    printf("graph : \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d -> ", ans[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nDisconnected part : \n");
            bfs(i);
            for (int i = 0; i < k; i++)
            {
                printf(" -> %d", ans[i]);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 2; i++)
    {
        plotter(i);
    }
}