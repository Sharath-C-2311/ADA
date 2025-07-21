#include <stdio.h>
#include <stdlib.h>

int bubble(int *arr, int n)
{
    int count = 0, flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    return count;
}

int main()
{
    int n = 10;
    FILE *f1, *f2, *f3;
    f1 = fopen("bsb.txt", "a");
    f2 = fopen("bsw.txt", "a");
    f3 = fopen("bsa.txt", "a");
    while (n <= 30000)
    {

        int *arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        int count = bubble(arr, n);

        fprintf(f1, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
        count = bubble(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        count = bubble(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n <= 1000)
        {
            n *= 10;
        }
        else
        {
            n += 10000;
        }
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}