#include <stdio.h>
#include <stdlib.h>

int table[50][50], n, m, w[50], v[50];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knap(int n, int m)
{
    if (table[n][m] == -1)
    {

        if (m < w[n])
        {
            table[n][m] = knap(n - 1, m);
        }
        else
        {
            table[n][m] = max(knap(n - 1, m), (v[n] + knap(n - 1, m - w[n])));
        }
    }
    return table[n][m];
}

int main()
{
    printf("Enter number of items : ");
    scanf("%d", &n);
    printf("Enter max weight : ");
    scanf("%d", &m);
    printf("Enter weight value\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else
            {
                table[i][j] = -1;
            }
        }
    }

    int a = knap(n, m);

    printf("Max : %d", a);

    printf("\ntable : \n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}